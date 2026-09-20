<script lang="ts">
	import type { AnswerStats } from "$lib/cppManager";
	import type { TimeManager } from "$lib/timeManager.svelte";
	import { onMount } from "svelte";
	import { fly } from "svelte/transition";

	interface Props {
		timeManager: TimeManager;
		getPrevAnswers: () => AnswerStats[];
	}

	let { timeManager, getPrevAnswers }: Props = $props();

	let prevAnswers: AnswerStats[] = $state([]);

	const colorify = (bool: boolean) => (bool ? "green" : "red");

	onMount(() => (prevAnswers = getPrevAnswers()));
</script>

<div class="gameover" in:fly={{ x: 500, y: 0, duration: 300, delay: 300 }}>
	<h2>Game over :C</h2>
	<div class="postgame">
		<p>
			Lasted {timeManager.displayifySeconds(timeManager.elapsedSeconds)} seconds
		</p>
		<table>
			<thead>
				<tr>
					<!-- <th></th> -->
					<th>word</th>
					<th>you said</th>
					<!-- <th>dictionary says</th> -->
					<th>correct?</th>
				</tr>
			</thead>
			<tbody>
				{#each prevAnswers as { word, correct, definition, real, response }, index}
					<tr>
						<!-- <td>{index}.</td> -->
						<td>{word}</td>
						<td class={colorify(response)}>
							{response ? "real" : "fake"}
						</td>
						<td class={colorify(real)}
							>{#if real}
								<a target="_blank" href={definition}>real</a>
							{:else}
								fake
							{/if}
						</td>
						<!-- <td class={colorify(correct)}>
							{correct ? "correct" : "incorrect"}</td
						> -->
					</tr>
				{/each}
			</tbody>
		</table>
	</div>
</div>

<style lang="scss">
	.gameover {
		display: flex;
		flex-direction: column;
		gap: 1rem;
		max-height: 100%;

		width: clamp(100px, 100%, 1000px);
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
		max-width: 100%;
		overflow: scroll;
	}

	p {
		text-align: center;
		font-size: 1.2rem;
	}

	table {
		width: 100%;
	}

	td {
		text-align: center;
	}

	h2 {
		font-size: 3rem;
		text-align: center;
	}

	a {
		color: var(--color);
	}

	.red,
	.green {
		color: var(--color);
	}

	.red {
		--color: #ef657a;
	}
	.green {
		--color: #98c379;
	}
</style>
