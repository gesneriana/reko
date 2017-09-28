import * as electron from 'electron';
import {app, BrowserWindow} from 'electron';

var mainWindow: Electron.BrowserWindow | null = null;

app.on('window-all-closed', function() {
	app.quit();
});

app.on('ready', function() {
	mainWindow = new BrowserWindow({
		width: 800,
		height: 600
	});

	mainWindow.loadURL('file://' + __dirname + '/index.html');

	mainWindow.on('closed', function() {
		mainWindow = null;
	});
});