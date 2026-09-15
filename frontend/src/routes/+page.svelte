<script lang="ts">
	// component imports
	import Compound from "$lib/components/Compound.svelte";
	import YesNo from "$lib/components/YesNo.svelte";

	// .ts imports
	import { getWord, getPrefix, isValid } from "$lib/logic";

	// svelte internal imports
	import { onMount } from "svelte";

	let word: string = $state("");
	let prefix: string = $state("");

	function updateWordAndPrefix() {
		word = getWord();
		prefix = getPrefix();
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
		<YesNo
			message="Is it a valid English word?"
			noAction={() => {}}
			yesAction={() => {}}
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

	main * {
		border-block: 1px solid black;
	}
</style>
