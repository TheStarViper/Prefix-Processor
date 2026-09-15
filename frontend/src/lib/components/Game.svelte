<script lang="ts">
	import { getWord, getPrefix, isValid } from "$lib/logic";
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

<section class="center">
	<h2>
		<span id="prefix">{prefix}-</span>
		<span id="plus">+</span>
		<span id="word">{word}</span>
	</h2>
</section>

<style>
	section.center {
		display: grid;
		min-height: 100vh;
		place-content: center;
	}

	h2 {
		width: 100vw;
		display: grid;
		grid-template-columns: 1fr max-content 1fr;
		align-items: center;
	}

	#prefix {
		text-align: right;
		color: #ef657a;
	}

	#word {
		color: #5dafef;
	}

	#prefix,
	#word {
		font-size: 5rem;
		font-family: "Courier New", Courier, monospace;
	}

	#plus {
		margin-inline: 1em;
		font-size: 3rem;
		font-family:
			"Gill Sans", "Gill Sans MT", Calibri, "Trebuchet MS", sans-serif;
		color: #111;
	}
</style>
