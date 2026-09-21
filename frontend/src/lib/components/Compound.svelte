<!-- The display module for the prefix + word combo -->

<script lang="ts">
	import type { TimeManager } from "$lib/timeManager.svelte";
	import { slide, fly } from "svelte/transition";

	interface Props {
		prefix: string;
		word: string;
		timeManager: TimeManager;
	}

	let { prefix, word, timeManager }: Props = $props();
</script>

<h2 out:fly={{ x: -500, y: 0, duration: 300 }}>
	<div>
		{#key prefix}
			<span id="prefix" class="red" transition:slide
				>{prefix ? prefix + "-" : ""}</span
			>
		{/key}
	</div>
	<span id="plus" class={timeManager.plusClass}>+</span>
	<div>
		{#key word}
			<span id="word" class="blue" transition:slide>{word}</span>
		{/key}
	</div>
</h2>

<style lang="scss">
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

			color: var(--color);

			&#prefix {
				margin-left: auto;
			}

			&#plus {
				margin-inline: 0.8em;
				font-size: 3rem;

				transition:
					color 0.1s ease-out,
					text-shadow 0.1s ease-out;
				color: var(--color, #111);
				text-shadow: 0 0 5px var(--color, transparent);
			}
		}
	}

	@media (width < 786px) {
		h2 {
			display: flex;
			flex-direction: column;

			span {
				font-size: 3rem;
				margin-inline: auto !important;
			}
		}
	}
</style>
