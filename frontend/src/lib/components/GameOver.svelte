<script lang="ts">
	import type { TimeManager } from "$lib/timeManager.svelte";
	import { fly } from "svelte/transition";

	interface Props {
		timeManager: TimeManager;
	}

	let { timeManager }: Props = $props();
</script>

<div class="container" in:fly={{ x: 500, y: 0, duration: 300, delay: 300 }}>
	<h2>Game over lol</h2>
	<div class="postgame">
		<p>
			Lasted {timeManager.displayifySeconds(timeManager.elapsedSeconds)} seconds
		</p>
	</div>
</div>

<style>
	.container {
		display: flex;
		flex-direction: column;
		gap: 1rem;
	}

	h2,
	.postgame {
		padding: 1rem;
		border: 2px solid #000;
		box-shadow: 4px 4px 0 #000;
		border-radius: var(--radius);
		text-align: center;
	}

	h2 {
		font-size: 3rem;
	}
</style>
