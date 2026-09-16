<!-- The display module for the prefix + word combo -->

<script lang="ts">
	import { slide } from "svelte/transition";

	interface Props {
		prefix: string;
		word: string;
	}

	let { prefix, word }: Props = $props();
</script>

<div class="container">
	<h2>
		<div>
			{#key prefix}
				<span id="prefix" transition:slide
					>{prefix ? prefix + "-" : ""}</span
				>
			{/key}
		</div>
		<span id="plus">+</span>
		<div>
			{#key word}
				<span id="word" transition:slide>{word}</span>
			{/key}
		</div>
	</h2>
</div>

<style>
	.container {
		display: grid;
		min-height: 100%;
		place-content: center;
	}

	h2 {
		display: grid;
		grid-template-columns: 1fr max-content 1fr;
		align-items: center;

		span {
			display: flex;
			flex-direction: column;
			font-size: 5rem;
			width: fit-content;

			padding: 1rem;
			border: 2px solid #000;
			box-shadow: 4px 4px 0 #000;
			border-radius: var(--radius);
			margin-bottom: 1rem;

			&#prefix {
				margin-left: auto;
				color: #ef657a;
			}

			&#word {
				color: #5dafef;
			}

			&#plus {
				margin-inline: 0.8em;
				font-size: 3rem;
				color: #111;
			}
		}
	}
</style>
