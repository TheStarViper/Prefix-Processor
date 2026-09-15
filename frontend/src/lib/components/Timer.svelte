<script lang="ts">
	import { onMount } from "svelte";
	import { slide } from "svelte/transition";

	interface Props {
		seconds: number;
		outOfTime: () => void;
	}

	let { seconds, outOfTime }: Props = $props();

	let elapsedSeconds: number = $state(0);

	const clampPositive = (num: number) => Math.max(num, 0);

	let display = $derived(
		clampPositive(Math.round((seconds - elapsedSeconds) * 10) / 10),
	);

	onMount(() => {
		setInterval(() => {
			if (display > 0) elapsedSeconds += 0.1;
		}, 100);
	});

	$effect(() => {
		if (display === 0) outOfTime();
	});
</script>

<!--
	the fact that it's keyed to seconds and not display is very important btw.
	It means that the transition only triggers when the total seconds increases,
	not when time elapses.
-->
<div>
	{#key seconds}
		<span transition:slide={{ axis: "x" }}>{display}s</span>
	{/key}
</div>

<style>
	div {
		display: flex;
		flex-direction: row-reverse;
	}

	span {
		/*
		up to 3 main chars + 1 decimal point + 1 decimal point
		+ inline padding * 2
		*/
		min-width: calc(6ch + 3rem);

		font-size: 2rem;
		font-weight: 600;
		text-align: center;

		padding: 0.75rem 1.5rem;
		background-color: #fff;
		border: 2px solid #000;
		box-shadow: 4px 4px 0 #000;
	}
</style>
