<script lang="ts">
	import { TimeManager } from "$lib/timeManager.svelte";
	import { slide } from "svelte/transition";

	interface Props {
		timeManager: TimeManager;
	}

	let { timeManager }: Props = $props();

	let bars: number[] = $derived.by(() => {
		const remaining = Math.max(0, timeManager.remaining);
		const count = Math.floor(remaining / timeManager.STARTING_SECONDS);
		const remainder = remaining % timeManager.STARTING_SECONDS;

		const result = new Array(count).fill(timeManager.STARTING_SECONDS);
		if (remainder > 0 || count === 0) {
			result.push(remainder);
		}

		return result;
	});
</script>

<div id="timer">
	<div class="readout">
		<span>{timeManager.displayifySeconds(timeManager.remaining)}s</span>
		<span class="small">remaining</span>
	</div>

	{#each bars as bar, index (index)}
		<div class="progress" transition:slide={{ axis: "x", duration: 300 }}>
			<div
				class="progress-bar"
				style:width="{(bar / timeManager.STARTING_SECONDS) * 100}%"
			></div>
		</div>
	{/each}

	<div class="readout">
		<span>{timeManager.displayifySeconds(timeManager.elapsedSeconds)}s</span
		>
		<span class="small">elapsed</span>
	</div>
</div>

<style lang="scss">
	#timer {
		display: flex;
		align-items: center;
		width: 100%;
		max-width: 800px;
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
