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
		const remaining = Math.max(0, seconds - elapsedSeconds);
		const count = Math.floor(remaining / STARTING_SECONDS);
		const remainder = remaining % STARTING_SECONDS;

		const result = new Array(count).fill(STARTING_SECONDS);
		if (remainder > 0 || count === 0) {
			result.push(remainder);
		}

		return result;
	});

	function displayify(num: number): string {
		const clamped = Math.max(0, num);
		const rounded = Math.round(clamped * 10) / 10;
		return `${rounded}`;
	}

	onMount(() => {
		setInterval(() => {
			if (seconds - elapsedSeconds > 0) {
				elapsedSeconds += 0.1;
			} else {
				outOfTime();
			}
		}, 100);
	});
</script>

<div class="container">
	<div class="readout">
		<span>{displayify(elapsedSeconds)}s</span>
		<span class="small">elapsed</span>
	</div>

	{#each bars as bar, index (index)}
		<div class="progress" transition:slide={{ axis: "x", duration: 300 }}>
			<div
				class="progress-bar"
				style:width="{(bar / STARTING_SECONDS) * 100}%"
			></div>
		</div>
	{/each}

	<div class="readout">
		<span>{displayify(seconds - elapsedSeconds)}s</span>
		<span class="small">remaining</span>
	</div>
</div>

<style lang="scss">
	.container {
		display: flex;
		flex-direction: row;
		align-items: center;
		width: 50vw;
		gap: 1em;
	}

	.readout {
		display: flex;
		flex-direction: column;
		align-items: center;

		.small {
			font-size: 0.7em;
			font-variation-settings: "slnt" -7;
		}
	}

	.progress {
		width: 100%;
		background-color: #e0e0e0;
		border: 2px solid #000;
		box-shadow: 4px 4px 0 #000;
		height: 1.5rem;
		border-radius: var(--radius);
		overflow: hidden;
	}

	.progress-bar {
		height: 100%;
		background-color: #000;
		width: 0;
		transition: width 300ms var(--timing);
	}
</style>
