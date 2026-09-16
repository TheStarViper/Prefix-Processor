<script lang="ts">
	import { fly } from "svelte/transition";
</script>

<div in:fly={{ x: 500, y: 0, duration: 300, delay: 300 }}>
	<h2>
		<div>Game over lol</div>
	</h2>
</div>

<style>
	h2 {
		font-size: 5rem;

		padding: 1rem;
		border: 2px solid #000;
		box-shadow: 4px 4px 0 #000;
		border-radius: var(--radius);
	}
</style>
