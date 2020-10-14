package com.openplug.elips3.extension;

public class ASValue
{
	private long value;
	
	public ASValue()
	{
		this.value = 0;
	}
	
	private ASValue(long value)
	{
		this.value = value;
	}
	
	public native int toInt(ASContext ctxt);	
	public static native ASValue fromInt(ASContext ctxt, int val);
	
	public native long toUnsignedInt(ASContext ctxt);	
	public static native ASValue fromUnsignedInt(ASContext ctxt, long val);
	
	public native double toDouble(ASContext ctxt);	
	public static native ASValue fromDouble(ASContext ctxt, double val);
	
	public native boolean toBool(ASContext ctxt);	
	public static native ASValue fromBool(ASContext ctxt, boolean val);
	
	public native ASObject toASObject(ASContext ctxt);	
	public static native ASValue fromASObject(ASContext ctxt, ASObject val);
	
	public native String toString(ASContext ctxt);	
	public static native ASValue fromString(ASContext ctxt, String val);
	
	public native ASArray toASArray(ASContext ctxt);	
	public static native ASValue fromASArray(ASContext ctxt, ASArray val);
	
	public native int ASGetValueType(ASContext ctxt);	

	public native boolean ASIsValueUndefined(ASContext ctxt);
	
	public native boolean ASIsValueNullOrUndefined(ASContext ctxt);
	
	public native int ASValueForbidGCCollect(ASContext ctxt);
	
	public native int ASValueAllowGCCollect(ASContext ctxt);
}
