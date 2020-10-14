package com.openplug.elips3.extension;

public class ASObject 
{
	private long object;
	
	public ASObject()
	{
		this.object = 0;
	}
	
	private ASObject(long object)
	{
		this.object = object;
	}
	
	public static native int ASCreateObject(ASContext ctxt, String type, int argc, ASValue[] argv, ASObject obj);

	public native int ASGetProperty(ASContext ctxt, String s, ASValue val);
	
	public native int ASSetProperty(ASContext ctxt, String s, ASValue value);
	
	public native int ASCallProperty(ASContext ctxt, String s, int argc, ASValue[] argv, ASValue ret);
	
	public native int ASCall(ASContext ctxt, int argc, ASValue[] argv, ASValue ret);
}
