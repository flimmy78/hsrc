$NetBSD: patch-php__ext_ming.c,v 1.3 2015/08/29 15:46:14 taca Exp $

* Fix build problem with maintainer-zts PKG_OPTIONS.

--- php_ext/ming.c.orig	2013-06-08 14:46:45.000000000 +0000
+++ php_ext/ming.c
@@ -370,7 +370,7 @@ static SWFInput getInput_fromFileResourc
 
 	input = newSWFInput_file(file);
 	zend_list_addref(Z_LVAL_P(zfile));
-	zend_list_addref(zend_list_insert(input, le_swfinputp));
+	zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 	return input;
 }
 /* }}} */
@@ -410,7 +410,7 @@ PHP_METHOD(swfinput, __construct)
 
 	input = newSWFInput_bufferCopy((unsigned char *)data, data_len);
 
-	ret = zend_list_insert(input, le_swfinputp);
+	ret = zend_list_insert(input, le_swfinputp TSRMLS_CC);
 	object_init_ex(getThis(), input_class_entry_ptr);
 	add_property_resource(getThis(), "input", ret);
 	zend_list_addref(ret);
@@ -449,7 +449,7 @@ PHP_METHOD(swffontcollection, __construc
 
 	fc = newSWFFontCollection_fromFile(filename);
 	if(fc) 	{
-		ret = zend_list_insert(fc, le_swffontcollectionp);
+		ret = zend_list_insert(fc, le_swffontcollectionp TSRMLS_CC);
 		object_init_ex(getThis(), fontcollection_class_entry_ptr);
 		add_property_resource(getThis(), "fontcollection", ret);
 		zend_list_addref(ret);
@@ -479,7 +479,7 @@ PHP_METHOD(swffontcollection, getFont)
 	font = SWFFontCollection_getFont(getFontCollection(getThis() TSRMLS_CC), index);
 
 	if(font != NULL) {
-		ret = zend_list_insert(font, le_swffontp);
+		ret = zend_list_insert(font, le_swffontp TSRMLS_CC);
 		object_init_ex(return_value, font_class_entry_ptr);
 		add_property_resource(return_value, "font", ret);
 		zend_list_addref(ret);
@@ -527,7 +527,7 @@ PHP_METHOD(swfbrowserfont, __construct)
 
 	font = newSWFBrowserFont(name);
 	if(font) {
-		ret = zend_list_insert(font, le_swfbrowserfontp);
+		ret = zend_list_insert(font, le_swfbrowserfontp TSRMLS_CC);
 		object_init_ex(getThis(), browserfont_class_entry_ptr);
 		add_property_resource(getThis(), "browserfont", ret);
 		zend_list_addref(ret);
@@ -573,7 +573,7 @@ PHP_METHOD(swfcxform, __construct)
 		WRONG_PARAM_COUNT;
 	}
 
-	ret = zend_list_insert(cx, le_swfcxformp);
+	ret = zend_list_insert(cx, le_swfcxformp TSRMLS_CC);
 	object_init_ex(getThis(), cxform_class_entry_ptr);
 	add_property_resource(getThis(), "cx", ret);
 	zend_list_addref(ret);
@@ -736,7 +736,7 @@ PHP_METHOD(swfinitaction, __construct)
 		init = newSWFInitAction_withId(getAction(zaction TSRMLS_CC), id);
 	}
 
-	ret = zend_list_insert(init, le_swfinitactionp);
+	ret = zend_list_insert(init, le_swfinitactionp TSRMLS_CC);
 	object_init_ex(getThis(), initaction_class_entry_ptr);
 	add_property_resource(getThis(), "initaction", ret);
 	zend_list_addref(ret);
@@ -785,7 +785,7 @@ PHP_METHOD(swfaction, __construct)
 		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Couldn't compile actionscript");
 	}
 	
-	ret = zend_list_insert(action, le_swfactionp);
+	ret = zend_list_insert(action, le_swfactionp TSRMLS_CC);
 
 	object_init_ex(getThis(), action_class_entry_ptr);
 	add_property_resource(getThis(), "action", ret);
@@ -863,7 +863,7 @@ PHP_METHOD(swfbitmap, __construct)
 		input = newSWFInput_filename(Z_STRVAL_P(zfile));
 		if(input == NULL)
 			php_error(E_ERROR, "opening bitmap file failed");
-		zend_list_addref(zend_list_insert(input, le_swfinputp));
+		zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 		break;
 
 	default:
@@ -884,7 +884,7 @@ PHP_METHOD(swfbitmap, __construct)
 			maskinput = newSWFInput_filename(Z_STRVAL_P(zmask));
 			if(maskinput == NULL)
 				php_error(E_ERROR, "opening mask file failed");
-			zend_list_addref(zend_list_insert(maskinput, le_swfinputp));
+			zend_list_addref(zend_list_insert(maskinput, le_swfinputp TSRMLS_CC));
 			break;
 
 		default:
@@ -895,7 +895,7 @@ PHP_METHOD(swfbitmap, __construct)
 		/* XXX: this is very optimistic! is it really a JPEG ?!? */
 		bitmap_alpha = newSWFJpegWithAlpha_fromInput(input, maskinput);
 		if(bitmap_alpha) {
-			ret = zend_list_insert(bitmap_alpha, le_swfbitmapp);
+			ret = zend_list_insert(bitmap_alpha, le_swfbitmapp TSRMLS_CC);
 			object_init_ex(getThis(), bitmap_class_entry_ptr);
 			add_property_resource(getThis(), "bitmap", ret);
 			zend_list_addref(ret);
@@ -903,7 +903,7 @@ PHP_METHOD(swfbitmap, __construct)
 	} else {
 		bitmap = newSWFBitmap_fromInput(input);
 		if(bitmap) {
-			ret = zend_list_insert(bitmap, le_swfbitmapp);
+			ret = zend_list_insert(bitmap, le_swfbitmapp TSRMLS_CC);
 			object_init_ex(getThis(), bitmap_class_entry_ptr);
 			add_property_resource(getThis(), "bitmap", ret);
 			zend_list_addref(ret);
@@ -1164,7 +1164,7 @@ static zend_function_entry swfbuttonreco
 PHP_METHOD(swfbutton, __construct)
 {
 	SWFButton button = newSWFButton();
-	int ret = zend_list_insert(button, le_swfbuttonp);
+	int ret = zend_list_insert(button, le_swfbuttonp TSRMLS_CC);
 
 	object_init_ex(getThis(), button_class_entry_ptr);
 	add_property_resource(getThis(), "button", ret);
@@ -1297,7 +1297,7 @@ PHP_METHOD(swfbutton, addCharacter)
 
 	if(record != NULL)
 	{
-		ret = zend_list_insert(record, le_swfbuttonrecordp);
+		ret = zend_list_insert(record, le_swfbuttonrecordp TSRMLS_CC);
 		object_init_ex(return_value, buttonrecord_class_entry_ptr);
 		add_property_resource(return_value, "buttonrecord", ret);
 		zend_list_addref(ret);
@@ -1384,7 +1384,7 @@ PHP_METHOD(swfbutton, addSound)
 
 	if(item != NULL) {
 		/* try and create a soundinstance object */
-		ret = zend_list_insert(item, le_swfsoundinstancep);
+		ret = zend_list_insert(item, le_swfsoundinstancep TSRMLS_CC);
 		object_init_ex(return_value, soundinstance_class_entry_ptr);
 		add_property_resource(return_value, "soundinstance", ret);
 		zend_list_addref(ret);
@@ -1971,7 +1971,7 @@ PHP_METHOD(swfdisplayitem, getMatrix)
 	m = SWFDisplayItem_getMatrix(getDisplayItem(getThis() TSRMLS_CC));
 	if(m != NULL)
 	{
-		ret = zend_list_insert(m, le_swfmatrixp);
+		ret = zend_list_insert(m, le_swfmatrixp TSRMLS_CC);
 		object_init_ex(return_value, matrix_class_entry_ptr);
 		add_property_resource(return_value, "matrix", ret);
 		zend_list_addref(ret);
@@ -1992,7 +1992,7 @@ PHP_METHOD(swfdisplayitem, getCharacter)
 	c = SWFDisplayItem_getCharacter(getDisplayItem(getThis() TSRMLS_CC));
 	if(c != NULL)
 	{
-		ret = zend_list_insert(c, le_swfcharacterp);
+		ret = zend_list_insert(c, le_swfcharacterp TSRMLS_CC);
 		object_init_ex(return_value, character_class_entry_ptr);
 		add_property_resource(return_value, "character", ret);
 		zend_list_addref(ret);
@@ -2366,7 +2366,7 @@ PHP_METHOD(swffont, __construct)
 	
 	if(font)
 	{
-		ret = zend_list_insert(font, le_swffontp);
+		ret = zend_list_insert(font, le_swffontp TSRMLS_CC);
 		object_init_ex(getThis(), font_class_entry_ptr);
 		add_property_resource(getThis(), "font", ret);
 		zend_list_addref(ret);
@@ -2537,7 +2537,7 @@ PHP_METHOD(swffiltermatrix, __construct)
 	
 	matrix = newSWFFilterMatrix(cols, rows, values);
 	free(values); /* array is copied by libming */
-	ret = zend_list_insert(matrix, le_swffiltermatrixp);
+	ret = zend_list_insert(matrix, le_swffiltermatrixp TSRMLS_CC);
 	object_init_ex(getThis(), filtermatrix_class_entry_ptr);
 	add_property_resource(getThis(), "filtermatrix", ret);
 	zend_list_addref(ret);
@@ -2582,7 +2582,7 @@ PHP_METHOD(swfshadow, __construct)
 	}
 
 	shadow = newSWFShadow(angle, distance, strength);
-	ret = zend_list_insert(shadow, le_swfshadowp);
+	ret = zend_list_insert(shadow, le_swfshadowp TSRMLS_CC);
 	object_init_ex(getThis(), shadow_class_entry_ptr);
 	add_property_resource(getThis(), "shadow", ret);
 	zend_list_addref(ret);
@@ -2628,7 +2628,7 @@ PHP_METHOD(swfblur, __construct)
 	}
 
 	blur = newSWFBlur(blurX, blurY, passes);
-	ret = zend_list_insert(blur, le_swfblurp);
+	ret = zend_list_insert(blur, le_swfblurp TSRMLS_CC);
 	object_init_ex(getThis(), blur_class_entry_ptr);
 	add_property_resource(getThis(), "blur", ret);
 	zend_list_addref(ret);
@@ -2665,7 +2665,7 @@ static zend_function_entry swfblur_funct
 PHP_METHOD(swfgradient, __construct)
 {
 	SWFGradient gradient = newSWFGradient();
-	int ret = zend_list_insert(gradient, le_swfgradientp);
+	int ret = zend_list_insert(gradient, le_swfgradientp TSRMLS_CC);
 
 	object_init_ex(getThis(), gradient_class_entry_ptr);
 	add_property_resource(getThis(), "gradient", ret);
@@ -3076,7 +3076,7 @@ PHP_METHOD(swffilter, __construct)
 	if(filter == NULL)
 		WRONG_PARAM_COUNT;
 
-	ret = zend_list_insert(filter, le_swffilterp);
+	ret = zend_list_insert(filter, le_swffilterp TSRMLS_CC);
 	object_init_ex(getThis(), filter_class_entry_ptr);
 	add_property_resource(getThis(), "filter", ret);
 	zend_list_addref(ret);	
@@ -3115,7 +3115,7 @@ static zend_function_entry swffilter_fun
 PHP_METHOD(swfmorph, __construct)
 {
 	SWFMorph morph = newSWFMorphShape();
-	int ret = zend_list_insert(morph, le_swfmorphp);
+	int ret = zend_list_insert(morph, le_swfmorphp TSRMLS_CC);
 
 	object_init_ex(getThis(), morph_class_entry_ptr);
 	add_property_resource(getThis(), "morph", ret);
@@ -3147,7 +3147,7 @@ PHP_METHOD(swfmorph, getShape1)
 {
 	SWFMorph morph = getMorph(getThis() TSRMLS_CC);
 	SWFShape shape = SWFMorph_getShape1(morph);
-	int ret = zend_list_insert(shape, le_swfshapep);
+	int ret = zend_list_insert(shape, le_swfshapep TSRMLS_CC);
 
 	object_init_ex(return_value, shape_class_entry_ptr);
 	add_property_resource(return_value, "shape", ret);
@@ -3161,7 +3161,7 @@ PHP_METHOD(swfmorph, getShape2)
 {
 	SWFMorph morph = getMorph(getThis() TSRMLS_CC);
 	SWFShape shape = SWFMorph_getShape2(morph);
-	int ret = zend_list_insert(shape, le_swfshapep);
+	int ret = zend_list_insert(shape, le_swfshapep TSRMLS_CC);
 
 	object_init_ex(return_value, shape_class_entry_ptr);
 	add_property_resource(return_value, "shape", ret);
@@ -3205,7 +3205,7 @@ PHP_METHOD(swfsoundstream, __construct)
 		input = newSWFInput_filename(Z_STRVAL_P(zfile));
 		if(input == NULL)
 			php_error(E_ERROR, "opening sound file failed");
-		zend_list_addref(zend_list_insert(input, le_swfinputp));
+		zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 		break;
 
 	default:
@@ -3216,7 +3216,7 @@ PHP_METHOD(swfsoundstream, __construct)
 	sound = newSWFSoundStream_fromInput(input);
 	
 	if(sound) {
-		ret = zend_list_insert(sound, le_swfsoundstreamp);
+		ret = zend_list_insert(sound, le_swfsoundstreamp TSRMLS_CC);
 		object_init_ex(getThis(), soundstream_class_entry_ptr);
 		add_property_resource(getThis(), "soundstream", ret);
 		zend_list_addref(ret);
@@ -3331,7 +3331,7 @@ PHP_METHOD(swfsound, __construct)
 			input = newSWFInput_filename(Z_STRVAL_P(zfile));
 			if(input == NULL)
 				php_error(E_ERROR, "opening sound file failed");
-			zend_list_addref(zend_list_insert(input, le_swfinputp));
+			zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 			break;
 
 		default:
@@ -3343,7 +3343,7 @@ PHP_METHOD(swfsound, __construct)
 
 	if(sound != NULL)
 	{	
-		ret = zend_list_insert(sound, le_swfsoundp);
+		ret = zend_list_insert(sound, le_swfsoundp TSRMLS_CC);
 		object_init_ex(getThis(), sound_class_entry_ptr);
 		add_property_resource(getThis(), "sound", ret);
 		zend_list_addref(ret);
@@ -3479,7 +3479,7 @@ PHP_METHOD(swfvideostream, __construct)
 			input = newSWFInput_filename(Z_STRVAL_P(zfile));
 			if(input == NULL)
 				php_error(E_ERROR, "opening sound video failed");
-			zend_list_addref(zend_list_insert(input, le_swfinputp));
+			zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 			break;
 
 		default:
@@ -3496,7 +3496,7 @@ PHP_METHOD(swfvideostream, __construct)
 	}
 	
 	if(stream) {
-		ret = zend_list_insert(stream, le_swfvideostreamp);
+		ret = zend_list_insert(stream, le_swfvideostreamp TSRMLS_CC);
 		object_init_ex(getThis(), videostream_class_entry_ptr);
 		add_property_resource(getThis(), "videostream", ret);
 		zend_list_addref(ret);
@@ -3646,7 +3646,7 @@ PHP_METHOD(swfbinarydata, __construct)
 	bd = newSWFBinaryData((unsigned char *)data, data_len);
 	
 	if(bd) {
-		ret = zend_list_insert(bd, le_swfbinarydatap);
+		ret = zend_list_insert(bd, le_swfbinarydatap TSRMLS_CC);
 		object_init_ex(getThis(), binarydata_class_entry_ptr);
 		add_property_resource(getThis(), "binarydata", ret);
 		zend_list_addref(ret);
@@ -3704,7 +3704,7 @@ PHP_METHOD(swfprebuiltclip, __construct)
 		input = newSWFInput_filename(Z_STRVAL_P(zfile));
 		if(input == NULL)
 			php_error(E_ERROR, "opening prebuilt clip file failed");
-		zend_list_addref(zend_list_insert(input, le_swfinputp));
+		zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 		break;
 
 	default:
@@ -3715,7 +3715,7 @@ PHP_METHOD(swfprebuiltclip, __construct)
 	clip = newSWFPrebuiltClip_fromInput(input);
 	
 	if(clip) {
-		ret = zend_list_insert(clip, le_swfprebuiltclipp);
+		ret = zend_list_insert(clip, le_swfprebuiltclipp TSRMLS_CC);
 		object_init_ex(getThis(), prebuiltclip_class_entry_ptr);
 		add_property_resource(getThis(), "prebuiltclip", ret);
 		zend_list_addref(ret);
@@ -3768,7 +3768,7 @@ PHP_METHOD(swfmovie, __construct)
 		movie = newSWFMovie(); /* default version 4 */
 	}
 	
-	ret = zend_list_insert(movie, le_swfmoviep);
+	ret = zend_list_insert(movie, le_swfmoviep TSRMLS_CC);
 	
 	object_init_ex(getThis(), movie_class_entry_ptr);
 	add_property_resource(getThis(), "movie", ret);
@@ -3880,7 +3880,7 @@ PHP_METHOD(swfmovie, add)
 	item = SWFMovie_add_internal(movie, ublock);
 	if (item != NULL) {
 		/* try and create a displayitem object */
-		ret = zend_list_insert(item, le_swfdisplayitemp);
+		ret = zend_list_insert(item, le_swfdisplayitemp TSRMLS_CC);
 		object_init_ex(return_value, displayitem_class_entry_ptr);
 		add_property_resource(return_value, "displayitem", ret);
 		zend_list_addref(ret);
@@ -4242,7 +4242,7 @@ PHP_METHOD(swfmovie, streamMP3)
 			php_error(E_ERROR, "opening mp3 file failed");
 		}
 
-		zend_list_addref(zend_list_insert(input, le_swfinputp));
+		zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 		break;
 
 	default:
@@ -4327,7 +4327,7 @@ PHP_METHOD(swfmovie, startSound)
 	if(item != NULL)
 	{
 		/* try and create a soundinstance object */
-		ret = zend_list_insert(item, le_swfsoundinstancep);
+		ret = zend_list_insert(item, le_swfsoundinstancep TSRMLS_CC);
 		object_init_ex(return_value, soundinstance_class_entry_ptr);
 		add_property_resource(return_value, "soundinstance", ret);
 		zend_list_addref(ret);
@@ -4369,7 +4369,7 @@ PHP_METHOD(swfmovie, importChar)
 	character = SWFMovie_importCharacter(movie, libswf, name);
 	if(character != NULL)
 	{
-		ret = zend_list_insert(character, le_swfcharacterp);
+		ret = zend_list_insert(character, le_swfcharacterp TSRMLS_CC);
 		object_init_ex(return_value, character_class_entry_ptr);
 		add_property_resource(return_value, "character", ret);
 		zend_list_addref(ret);
@@ -4397,7 +4397,7 @@ PHP_METHOD(swfmovie, importFont)
 	if(res != NULL)
 	{
 		/* try and create a fontchar object */
-		ret = zend_list_insert(res, le_swffontcharp);
+		ret = zend_list_insert(res, le_swffontcharp TSRMLS_CC);
 		object_init_ex(return_value, fontchar_class_entry_ptr);
 		add_property_resource(return_value, "fontcharacter", ret);
 		zend_list_addref(ret);
@@ -4424,7 +4424,7 @@ PHP_METHOD(swfmovie, addFont)
 	if(res != NULL)
 	{
 		/* try and create a fontchar object */
-		ret = zend_list_insert(res, le_swffontcharp);
+		ret = zend_list_insert(res, le_swffontcharp TSRMLS_CC);
 		object_init_ex(return_value, fontchar_class_entry_ptr);
 		add_property_resource(return_value, "fontcharacter", ret);
 		zend_list_addref(ret);
@@ -4509,7 +4509,7 @@ static zend_function_entry swfmovie_func
 PHP_METHOD(swfshape, __construct)
 {
 	SWFShape shape = newSWFShape();
-	int ret = zend_list_insert(shape, le_swfshapep);
+	int ret = zend_list_insert(shape, le_swfshapep TSRMLS_CC);
 
 	object_init_ex(getThis(), shape_class_entry_ptr);
 	add_property_resource(getThis(), "shape", ret);
@@ -4575,7 +4575,7 @@ PHP_METHOD(swfshape, addSolidFill)
 	}
 
 	/* return an SWFFill object */
-	ret = zend_list_insert(fill, le_swffillp);
+	ret = zend_list_insert(fill, le_swffillp TSRMLS_CC);
 	object_init_ex(return_value, fill_class_entry_ptr);
 	add_property_resource(return_value, "fill", ret);
 	zend_list_addref(ret);
@@ -4618,7 +4618,7 @@ PHP_METHOD(swfshape, addBitmapFill)
 	}
 
 	/* return an SWFFill object */
-	ret = zend_list_insert(fill, le_swffillp);
+	ret = zend_list_insert(fill, le_swffillp TSRMLS_CC);
 	object_init_ex(return_value, fill_class_entry_ptr);
 	add_property_resource(return_value, "fill", ret);
 	zend_list_addref(ret);
@@ -4664,7 +4664,7 @@ PHP_METHOD(swfshape, addGradientFill)
 	}
 
 	/* return an SWFFill object */
-	ret = zend_list_insert(fill, le_swffillp);
+	ret = zend_list_insert(fill, le_swffillp TSRMLS_CC);
 	object_init_ex(return_value, fill_class_entry_ptr);
 	add_property_resource(return_value, "fill", ret);
 	zend_list_addref(ret);
@@ -4719,7 +4719,7 @@ PHP_METHOD(swfshape, addFill)
 	}
 
 	/* return an SWFFill object */
-	ret = zend_list_insert(fill, le_swffillp);
+	ret = zend_list_insert(fill, le_swffillp TSRMLS_CC);
 	object_init_ex(return_value, fill_class_entry_ptr);
 	add_property_resource(return_value, "fill", ret);
 	zend_list_addref(ret);
@@ -5209,7 +5209,7 @@ static zend_function_entry swfshape_func
 PHP_METHOD(swfsprite, __construct)
 {
 	SWFMovieClip sprite = newSWFMovieClip();
-	int ret = zend_list_insert(sprite, le_swfspritep);
+	int ret = zend_list_insert(sprite, le_swfspritep TSRMLS_CC);
 
 	object_init_ex(getThis(), sprite_class_entry_ptr);
 	add_property_resource(getThis(), "sprite", ret);
@@ -5259,7 +5259,7 @@ PHP_METHOD(swfsprite, add)
 
 	if (item != NULL) {
 		/* try and create a displayitem object */
-		ret = zend_list_insert(item, le_swfdisplayitemp);
+		ret = zend_list_insert(item, le_swfdisplayitemp TSRMLS_CC);
 		object_init_ex(return_value, displayitem_class_entry_ptr);
 		add_property_resource(return_value, "displayitem", ret);
 		zend_list_addref(ret);
@@ -5342,7 +5342,7 @@ PHP_METHOD(swfsprite, startSound)
 
 	if(item != NULL) {
 		/* try and create a displayitem object */
-		ret = zend_list_insert(item, le_swfsoundinstancep);
+		ret = zend_list_insert(item, le_swfsoundinstancep TSRMLS_CC);
 		object_init_ex(return_value, soundinstance_class_entry_ptr);
 		add_property_resource(return_value, "soundinstance", ret);
 		zend_list_addref(ret);
@@ -5400,7 +5400,7 @@ PHP_METHOD(swfsprite, setSoundStream)
 		input = newSWFInput_filename(Z_STRVAL_P(zfile));
 		if(input == NULL)
 			php_error(E_ERROR, "opening sound file failed");
-		zend_list_addref(zend_list_insert(input, le_swfinputp));
+		zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 		break;
 
 	}
@@ -5521,7 +5521,7 @@ PHP_METHOD(swftext, __construct)
 		text = newSWFText2();
 	}
 
-	int ret = zend_list_insert(text, le_swftextp);
+	int ret = zend_list_insert(text, le_swftextp TSRMLS_CC);
 	object_init_ex(getThis(), text_class_entry_ptr);
 	add_property_resource(getThis(), "text", ret);
 	zend_list_addref(ret);
@@ -5794,7 +5794,7 @@ PHP_METHOD(swftextfield, __construct)
 {
 	long flags = 0;
 	SWFTextField field = newSWFTextField();
-	int ret = zend_list_insert(field, le_swftextfieldp);
+	int ret = zend_list_insert(field, le_swftextfieldp TSRMLS_CC);
 
 	object_init_ex(getThis(), textfield_class_entry_ptr);
 	add_property_resource(getThis(), "textfield", ret);
