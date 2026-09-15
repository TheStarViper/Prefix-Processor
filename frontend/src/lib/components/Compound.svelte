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
		margin-inline: 0.8em;
		font-size: 3rem;
		color: #111;
	}
</style>
