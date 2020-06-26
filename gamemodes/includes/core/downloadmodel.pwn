public OnPlayerRequestDownload(playerid, type, crc)
{
	if(!IsPlayerConnected(playerid))
		return 0;
                    
	new filename[64], filefound, final_url[256];
                
	if(type == DOWNLOAD_REQUEST_TEXTURE_FILE)
		filefound = FindTextureFileNameFromCRC(crc, filename, sizeof(filename));
	else if(type == DOWNLOAD_REQUEST_MODEL_FILE)
		filefound = FindModelFileNameFromCRC(crc, filename, sizeof(filename));
                    
	if(filefound)
	{
		format(final_url, sizeof(final_url), "%s/%s", DOWNLOAD_WEB, filename);
		RedirectDownload(playerid, final_url);
	}
	return 1;
}