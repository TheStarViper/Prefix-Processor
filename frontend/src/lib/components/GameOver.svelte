<script lang="ts">
	import type { TimeManager } from "$lib/timeManager.svelte";
	import { onMount } from "svelte";
	import { fly } from "svelte/transition";

	interface Props {
		timeManager: TimeManager;
		getPrevAnswers: () => [string, boolean][];
	}

	let { timeManager, getPrevAnswers }: Props = $props();

	let prevAnswers: [string, boolean][] = $state([]);

	onMount(() => (prevAnswers = getPrevAnswers()));
</script>

<div class="container" in:fly={{ x: 500, y: 0, duration: 300, delay: 300 }}>
	<h2>Game over lol</h2>
	<div class="postgame">
		<p>
			Lasted {timeManager.displayifySeconds(timeManager.elapsedSeconds)} seconds
		</p>
		<ol>
			{#each prevAnswers as prevAnswer}
				<li>
					<span>
						<span>{prevAnswer[0]}:</span>
						<span class={prevAnswer[1] ? "gren" : "red"}
							>{prevAnswer[1] ? "correct" : "incorrect"}</span
						>
					</span>
				</li>
			{/each}
		</ol>
	</div>
</div>

<style>
	.container {
		display: flex;
		flex-direction: column;
		gap: 1rem;
		padding-block: 0.5rem;
		max-height: 100%;
	}

	h2,
	.postgame {
		padding: 1rem;
		border: 2px solid #000;
		box-shadow: 4px 4px 0 #000;
		border-radius: var(--radius);
	}

	.postgame {
		max-height: 100%;
		overflow-y: scroll;
	}

	p {
		text-align: center;
		font-size: 1.2rem;
	}

	h2 {
		font-size: 3rem;
	}

	li > span {
		display: flex;
		justify-content: space-between;
	}

	.red,
	.gren {
		color: var(--color);
	}

	.red {
		--color: #ef657a;
	}
	.gren {
		--color: #98c379;
	}
</style>
