import React from "react";
import { useState, useEffect } from "react";

function Hello() {
	useEffect(() => {
		console.log("created :)");
		// return (() => {
		// 	console.log("destroyed :(");
		// });
	}, []);
	return (
		<h1>Hello</h1>
	);
}

function App() {
	const [showing, setShowing] = useState(false);
	const changeShowing = () => {
		setShowing(currentValue => !currentValue);
	};
	return (
		<div>
			{showing ? <Hello/> : null}
			<button onClick={changeShowing}>
				{showing ? "Hide" : "Show"}
			</button>
		</div>
  	);
}

export default App;