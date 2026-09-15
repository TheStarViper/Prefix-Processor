<script module>
	export const STARTING_SECONDS = 30;
</script>

<script lang="ts">
	import { onMount } from "svelte";
	import { slide } from "svelte/transition";

	interface Props {
		seconds: number;
		outOfTime: () => void;
	}

	let { seconds, outOfTime }: Props = $props();

	let elapsedSeconds: number = $state(0);

	let bars: number[] = $derived.by(() => {
		const fullBars = Array.from({
			length: Math.floor((seconds - elapsedSeconds) / STARTING_SECONDS),
		}).map(() => STARTING_SECONDS);

		const remainder = (seconds - elapsedSeconds) % STARTING_SECONDS;

		if (fullBars.length === 0) return [remainder];

		if (remainder === 0) return fullBars;

		return [...fullBars, remainder];
	});

	onMount(() => {
		setInterval(() => {
			elapsedSeconds += 0.1;
			if (seconds - elapsedSeconds <= 0) outOfTime();
		}, 100);
	});
</script>

<div class="container">
	<span>{Math.round((seconds - elapsedSeconds) * 10) / 10}s</span>

	{#each bars as bar, index (index)}
		<div class="progress" transition:slide={{ axis: "x", duration: 300 }}>
			<div
				class="progress-bar"
				style:width="{(bar / STARTING_SECONDS) * 100}%"
			></div>
		</div>
	{/each}
</div>

<style>
	span {
		min-width: 5ch;
	}

	.container {
		display: flex;
		flex-direction: row;
		width: 50vw;
		gap: 1em;
	}

	.progress {
		width: 100%;
		background-color: #e0e0e0;
		border: 2px solid #000;
		box-shadow: 4px 4px 0 #000;
		height: 1.5rem;
	}

	.progress-bar {
		height: 100%;
		background-color: #000;
		width: 0;
		transition: width 300ms var(--timing);
	}
</style>
