<script lang="ts">
	// component imports
	import Compound from "$lib/components/Compound.svelte";
	import YesNo from "$lib/components/YesNo.svelte";

	// svelte internal imports
	import { onMount } from "svelte";

	// misc imports
	import { getWord, getPrefix, isValid } from "$lib/logic";
	import confetti from "canvas-confetti";
	import { decodeSounds } from "$lib/sound";

	let word: string = $state("");
	let prefix: string = $state("");

	function updateWordAndPrefix() {
		word = getWord();
		prefix = getPrefix();
	}

	function checkAnswer(answer: boolean) {
		// This is the first guaranteed user interaction, so we hijack it to
		// decode the sounds
		decodeSounds();

		if (answer === isValid(word, prefix)) {
			correct();
		} else {
			wrong();
		}

		updateWordAndPrefix();
	}

	function correct() {
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
	}

	function wrong() {
		console.warn("*buzzer sound* wrong!");
	}

	onMount(() => {
		updateWordAndPrefix();
	});
</script>

<main>
	<header></header>

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

	main * {
		border-block: 1px solid black;
	}
</style>
