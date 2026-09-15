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
		border-radius: 0.6em;
		background: var(--button-bg);
		border: 2px solid color-mix(in srgb, var(--button-bg) 90%, black);

		font-size: 2rem;
		color: #111;

		box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);

		transition:
			filter 0.1s var(--timing),
			transform 0.2s var(--timing),
			box-shadow 0.2s var(--timing);
	}

	button:hover {
		filter: saturate(130%);
		transform: translateY(-0.15em);
		box-shadow: 0 4px 15px rgba(0, 0, 0, 0.6);
	}

	#yes {
		--button-bg: #98c379;
	}
	#no {
		--button-bg: #ef657a;
	}
</style>
