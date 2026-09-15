<script lang="ts">
	interface Props {
		message: string;
		action: (response: boolean) => void;
	}

	let { message, action }: Props = $props();
</script>

<div id="yesno">
	<p>{message}</p>

	<div class="buttons">
		<button id="yes" onclick={() => action(true)}>Yes</button>
		<button id="no" onclick={() => action(false)}>No</button>
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
