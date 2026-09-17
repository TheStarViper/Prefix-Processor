<script lang="ts">
	// component imports
	import Compound from "$lib/components/Compound.svelte";
	import YesNo from "$lib/components/YesNo.svelte";
	import Timer from "$lib/components/Timer.svelte";
	import GameOver from "$lib/components/GameOver.svelte";

	// svelte internal imports
	import { onMount } from "svelte";

	// misc imports
	import confetti from "canvas-confetti";
	import { playSound } from "$lib/sound";
	import { TimeManager } from "$lib/timeManager.svelte";
	import { CppManager } from "$lib/cppManager";

	let word: string = $state("");
	let prefix: string = $state("");

	const cppManager = new CppManager(
		(newWord: string) => {
			word = newWord;
		},
		(newPrefix: string) => {
			prefix = newPrefix;
		},
	);
	const timeManager = new TimeManager();

	function checkAnswer(response: boolean) {
		const isCorrect = cppManager.submitAnswer(response);

		if (isCorrect) {
			timeManager.seconds += timeManager.CORRECT_SECONDS;

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
		} else {
			playSound("incorrect.wav");
			timeManager.seconds += timeManager.INCORRECT_SECONDS;
		}
	}

	function handleGameoverYesNo(response: boolean) {
		if (response) {
			window.location.reload();
		} else {
			alert("pretend that we have a menu screen lol");
		}
	}

	let message = $derived(
		timeManager.stillHasTime
			? "Is it a valid English word?"
			: "Start new game?",
	);

	onMount(() => {
		cppManager.init();
		timeManager.init();
	});
</script>

<main>
	<header>
		<Timer {timeManager} />
	</header>

	<section id="center">
		{#if timeManager.stillHasTime}
			<Compound {word} {prefix} />
		{:else}
			<GameOver />
		{/if}
	</section>

	<section>
		<YesNo
			{message}
			action={timeManager.stillHasTime
				? checkAnswer
				: handleGameoverYesNo}
		/>
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
