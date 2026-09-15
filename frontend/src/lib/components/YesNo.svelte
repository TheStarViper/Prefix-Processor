<script lang="ts">
	import { decodeSounds } from "$lib/sound";

	interface Props {
		message: string;
		action: (response: boolean) => void;
	}

	let { message, action }: Props = $props();

	const interact = async (...params: Parameters<typeof action>) => {
		// This is the first guaranteed user interaction, so we hijack it to
		// decode the sounds
		await decodeSounds();

		action(...params);
	};
</script>

<div id="yesno">
	<p>{message}</p>

	<div class="buttons">
		<button id="yes" onclick={() => interact(true)}>Yes</button>
		<button id="no" onclick={() => interact(false)}>No</button>
	</div>
</div>

<style>
	#yesno {
		display: grid;
		height: 100%;
		width: 100%;
		grid-template-rows: 1fr 3fr;
		align-items: center;
		padding: 1rem;
	}

	p {
		text-align: center;
		font-size: 1.5rem;
		font-variation-settings: "slnt" -7;
	}

	.buttons {
		display: flex;
		justify-content: center;
		height: 100%;
		width: clamp(100px, 100%, 1000px);
		margin-inline: auto;

		gap: 2rem;
	}

	button {
		height: 100%;
		width: 100%;

		background: var(--button-bg);

		font-size: 2rem;
		text-align: center;
		color: #000;
		font-style: oblique;

		padding: 0.75rem 1.5rem;

		background-color: #fff;
		border: 2px solid #000;
		box-shadow: 4px 4px 0 #000;

		transition:
			color 0.15s var(--timing),
			transform 0.2s var(--timing),
			box-shadow 0.2s var(--timing);
	}

	button:hover,
	button:active {
		color: var(--button-color);
		transform: translateY(-0.15em);
		box-shadow: 6px 6px 0 var(--button-color);
	}

	#yes {
		--button-color: #98c379;
	}
	#no {
		--button-color: #ef657a;
	}
</style>
