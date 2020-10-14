package com.openplug.elips3.extension;

public class ASContext
{
	private long context;
	
	public ASContext()
	{
		this.context = 0;
	}
	
	private ASContext(long context)
	{
		this.context = context;
	}
	
	public native int ASCtxtSetUserData(long userData);
	
	public native long ASCtxtGetUserData();
	
	public native int ASCtxtEnableExceptionCatch(boolean enable);
	
	public native ASValue ASCtxtGetLastException();
	
	public native long ASCtxtGetPlatformSpecificData();
}
