<script lang="ts">
	// component imports
	import Compound from "$lib/components/Compound.svelte";
	import YesNo from "$lib/components/YesNo.svelte";
	import GameOver from "$lib/components/GameOver.svelte";

	// svelte internal imports
	import { onMount } from "svelte";

	// misc imports
	import confetti from "canvas-confetti";
	import { playSound } from "$lib/sound";
	import Timer, { STARTING_SECONDS } from "$lib/components/Timer.svelte";
	import MainModuleFactory from "$lib/cpp/cpp_module";

	let word: string = $state("");
	let prefix: string = $state("");

	let seconds: number = $state(STARTING_SECONDS);
	let stillHasTime = $state(true);

	function checkAnswer(answer: boolean) {
		if (answer === isValid()) {
			correct();
		} else {
			wrong();
		}

		updateWordAndPrefix();
	}

	function correct() {
		playSound("correct.wav");
		confetti({
			particleCount: 150,
			startVelocity: 55,
			angle: 60,
			spread: 50,
			origin: { x: 0 },
		});
		confetti({
			particleCount: 150,
			startVelocity: 55,
			angle: 120,
			spread: 50,
			origin: { x: 1 },
		});

		seconds += 2;
	}

	function wrong() {
		playSound("incorrect.wav");
		seconds -= 5;
	}

	function outOfTime() {
		stillHasTime = false;
	}

	let updateWordAndPrefix = () => {};
	let isValid = () => false;

	onMount(async () => {
		const Module = await MainModuleFactory();

		Module._load_dictionary();
		Module._generate_game_question();
		Module._randomize_prefix();

		const get_current_base: () => string = Module.cwrap(
			"get_current_base",
			"string",
			[],
		);

		const fetch_cached_prefix: () => string = Module.cwrap(
			"fetch_cached_prefix",
			"string",
			[],
		);

		const get_current_is_valid: () => number = Module.cwrap(
			"get_current_is_valid",
			"number",
			[],
		);

		updateWordAndPrefix = () => {
			Module._generate_game_question();

			word = get_current_base();
			prefix = fetch_cached_prefix();
		};

		isValid = () => {
			const res = get_current_is_valid();
			return res === 1;
		};

		updateWordAndPrefix();
	});
</script>

<main>
	<header>
		<Timer {seconds} {outOfTime} />
	</header>

	<section id="center">
		{#if stillHasTime}
			<Compound {word} {prefix} />
		{:else}
			<GameOver />
		{/if}
	</section>

	<section>
		<YesNo message="Is it a valid English word?" action={checkAnswer} />
	</section>
</main>

<style>
	:root {
		--header-height: 100px;
	}

	main {
		height: 100vh;
		overflow: hidden;

		display: grid;
		grid-template-rows: var(--header-height) 3fr 2fr;
	}

	main > section {
		border-block: 1px solid black;
	}

	#center {
		display: flex;
		flex-direction: row;
		justify-content: center;
		align-items: center;
		min-height: 100%;
	}

	header {
		height: 100%;
		display: grid;
		place-content: center;
	}
</style>
