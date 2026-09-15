<!-- The display module for the prefix + word combo -->

<script lang="ts">
	interface Props {
		prefix: string;
		word: string;
	}

	let { prefix, word }: Props = $props();
</script>

<div>
	<h2>
		<span id="prefix">{prefix}-</span>
		<span id="plus">+</span>
		<span id="word">{word}</span>
	</h2>
</div>

<style>
	div {
		display: grid;
		min-height: 100%;
		place-content: center;
	}

	h2 {
		width: 100vw;
		display: grid;
		grid-template-columns: 1fr max-content 1fr;
		align-items: center;
	}

	#prefix {
		text-align: right;
		color: #ef657a;
	}

	#word {
		color: #5dafef;
	}

	#prefix,
	#word {
		font-size: 5rem;
		font-family: "Courier New", Courier, monospace;
	}

	#plus {
		margin-inline: 1em;
		font-size: 3rem;
		font-family:
			"Gill Sans", "Gill Sans MT", Calibri, "Trebuchet MS", sans-serif;
		color: #111;
	}
</style>
