package com.openplug.elips3.extension;

public class ASArray
{
	private long array;
	
	public ASArray()
	{
		this.array = 0;
	}
	
	private ASArray(long array)
	{
		this.array = array;
	}
	
	public static native int ASCreateArray(ASContext ctxt, int length, ASArray array);

	public native ASValue ASArrayGet(ASContext ctxt, int i);
	
	public native int ASArraySet(ASContext ctxt, int i, ASValue val);
	
	public native int ASArrayLength(ASContext ctxt);
}
