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

	<link rel="preconnect" href="https://fonts.googleapis.com" />
	<link rel="preconnect" href="https://fonts.gstatic.com" />
	<link
		href="https://fonts.googleapis.com/css2?family=Recursive:slnt,CASL,CRSV,MONO@-15..0,0,1,0.52&display=swap"
		rel="stylesheet"
	/>
</svelte:head>

{@render children()}
