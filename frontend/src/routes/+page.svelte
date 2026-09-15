<script lang="ts">
	// component imports
	import Compound from "$lib/components/Compound.svelte";
	import YesNo from "$lib/components/YesNo.svelte";

	// svelte internal imports
	import { onMount } from "svelte";

	// misc imports
	import { getWord, getPrefix, isValid } from "$lib/logic";
	import confetti from "canvas-confetti";
	import { playSound } from "$lib/sound";
	import Timer from "$lib/components/Timer.svelte";

	let word: string = $state("");
	let prefix: string = $state("");

	let seconds: number = $state(30);

	function updateWordAndPrefix() {
		word = getWord();
		prefix = getPrefix();
	}

	function checkAnswer(answer: boolean) {
		if (answer === isValid(word, prefix)) {
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
		alert("Out of time!");
	}

	onMount(() => {
		updateWordAndPrefix();
	});
</script>

<main>
	<header>
		<Timer {seconds} {outOfTime} />
	</header>

	<section>
		<Compound {word} {prefix} />
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

	header {
		height: 100%;
		display: grid;
		place-content: center;
	}

	h1 {
		text-align: center;
		font-size: 4rem;
	}
</style>
