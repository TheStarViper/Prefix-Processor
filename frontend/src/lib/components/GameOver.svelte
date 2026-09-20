<script lang="ts">
	import type { Answer, AnswerMetrics, CppManager } from "$lib/cppManager";
	import type { TimeManager } from "$lib/timeManager.svelte";
	import { onMount } from "svelte";
	import { fly } from "svelte/transition";

	interface Props {
		timeManager: TimeManager;
		cppManager: CppManager;
	}

	let { timeManager, cppManager }: Props = $props();

	let answers: Answer[] = $state([]);
	let metrics: AnswerMetrics = $state(cppManager.createAnswerMetrics());

	const colorify = (bool: boolean) => (bool ? "green" : "red");

	onMount(() => {
		answers = cppManager.getAnswers();
		metrics = cppManager.calcMetrics(answers);
	});
</script>

<div class="gameover" in:fly={{ x: 500, y: 0, duration: 300, delay: 300 }}>
	<h2>Game over :C</h2>

	<div class="postgame">
		{#if answers.length > 0}
			<p>
				Lasted {timeManager.displayifySeconds(
					timeManager.elapsedSeconds,
				)} seconds
			</p>
			<div id="metrics">
				<div>
					<h4>You</h4>
					<span>{metrics.response}/{metrics.count}</span>
				</div>

				<div>
					<h4>Dictionary</h4>
					<span>{metrics.real}/{metrics.count}</span>
				</div>

				<div>
					<h4>Correct</h4>
					<span>{metrics.correct}/{metrics.count}</span>
				</div>
			</div>
			<table>
				<thead>
					<tr>
						<!-- <th></th> -->
						<th>word</th>
						<th>you said</th>
						<th>dictionary says</th>
						<th>correct?</th>
					</tr>
				</thead>
				<tbody>
					{#each answers as { word, correct, definition, real, response }, index}
						<tr>
							<!-- <td>{index}.</td> -->
							<td>{word}</td>
							<td class={colorify(response)}>
								{response ? "real" : "fake"}
							</td>
							<td class={colorify(real)}>
								{#if real}
									<a target="_blank" href={definition}>real</a
									>
								{:else}
									fake
								{/if}
							</td>
							<td class={colorify(correct)}>
								{correct ? "correct" : "incorrect"}</td
							>
						</tr>
					{/each}
				</tbody>
			</table>
		{:else}
			<p>
				You didn't answer any words before time ran out. Next time, try
				guessing whether a word is real or not!
			</p>
		{/if}
	</div>
</div>

<style lang="scss">
	.gameover {
		display: flex;
		flex-direction: column;
		gap: 1rem;
		max-height: 100%;

		width: clamp(100px, 100%, 1000px);

		& > * {
			padding: 1rem;
			border: 2px solid #000;
			box-shadow: 4px 4px 0 #000;
			border-radius: var(--radius);
		}

		h2 {
			font-size: 3rem;
			text-align: center;
		}

		.postgame {
			max-height: 100%;
			max-width: 100%;
			overflow: scroll;

			display: flex;
			flex-direction: column;
			gap: 1rem;

			p {
				text-align: center;
				margin-inline: auto;
				font-size: 1.2rem;
				max-width: 65ch;
			}

			#metrics {
				display: flex;
				width: 100%;
				justify-content: space-evenly;

				div {
					display: flex;
					flex-direction: column-reverse;
					text-align: center;

					span {
						font-weight: bold;
						font-size: 1.5rem;
					}

					h4 {
						font-weight: normal;
					}
				}
			}

			table {
				width: 100%;

				td {
					text-align: center;

					&,
					a {
						color: var(--color);
					}
				}
			}
		}
	}

	.red {
		--color: #ef657a;
	}
	.green {
		--color: #98c379;
	}
</style>
