<script lang="ts">
	import favicon from "$lib/assets/favicon.svg";
	import "$lib/assets/reset.css";
	import "$lib/assets/global.css";
	import { onMount } from "svelte";
	import { preloadSounds } from "$lib/sound";

	let { children } = $props();

	onMount(preloadSounds);
</script>

<svelte:head>
	<link rel="icon" href={favicon} />
</svelte:head>

{@render children()}
