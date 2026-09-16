<script lang="ts">
	import { fly } from "svelte/transition";
</script>

<h2 transition:fly={{ x: 500, y: 0, duration: 300, delay: 300 }}>
	<div>Game over lol</div>
</h2>

<style>
	h2 {
		font-size: 5rem;
	}
</style>
