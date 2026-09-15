<script lang="ts">
	interface Props {
		message: string;
		yesAction: () => void;
		noAction: () => void;
	}

	let { message, yesAction, noAction }: Props = $props();
</script>

<div id="yesno">
	<p>{message}</p>

	<div class="buttons">
		<button id="yes" onclick={yesAction}>Yes</button>
		<button id="no" onclick={noAction}>No</button>
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
	}
</style>
