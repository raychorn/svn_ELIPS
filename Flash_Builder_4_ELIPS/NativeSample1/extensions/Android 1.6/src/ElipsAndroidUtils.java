package com.openplug.elips3.extension;

import com.openplug.ElipsUtils;

import android.content.Context;
import android.view.View;

public class ElipsAndroidUtils {
	/**
	 * Gets the Android Context
	 * @return the android Context
	 */
	public static Context getContext()
	{
		return ElipsUtils.getContext();
	}
	
	/**
	 * @brief From an ELIPS DisplayObject, get, if available, the associated view
	 *
	 * If no view is associated to the given DisplayObject, null is returned.
	 *
	 * @param[in]    ctxt				The AS context.
	 * @param[in]    displayObject		DisplayObject on which we want to get the corresponding view.
	 *
	 * @return               null if no native view is associated to the passed displayObject
	 */
	public native static View getViewFromDisplayObject(ASContext ctxt, ASObject displayObject);
	
	/**
	 * @brief From a view, get, if available, the associated ELIPS DisplayObject
	 *
	 * If no DisplayObject is associated to the given native view, null is returned.
	 *
	 * @param[in]    ctxt				The AS context.
	 * @param[in]    view				view on which we want to get the corresponding ELIPS DisplayObject.
	 *
	 * @return               null if no view is associated to the passed displayObject
	 */
	public native static ASObject getDisplayObjectFromView(ASContext ctxt, View view);
}
