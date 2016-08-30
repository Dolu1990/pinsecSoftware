/**
 * This file has a different license to the rest of the uGFX system.
 * You can copy, modify and distribute this file as you see fit.
 * You do not need to publish your source modifications to this file.
 * The only thing you are not permitted to do is to relicense it
 * under a different license.
 */

/**
 * Copy this file into your project directory and rename it as gfxconf.h
 * Edit your copy to turn on the uGFX features you want to use.
 * The values below are the defaults.
 *
 * Only remove the comments from lines where you want to change the
 * default value. This allows definitions to be included from
 * driver makefiles when required and provides the best future
 * compatibility for your project.
 *
 * Please use spaces instead of tabs in this file.
 */

#ifndef _GFXCONF_H
#define _GFXCONF_H


/* OS */
#define GFX_USE_OS_RAW32        TRUE

/* GFX sub-systems to turn on */
#define GFX_USE_GDISP			TRUE
/*#define GFX_USE_GWIN			TRUE*/

/* Features for the GDISP sub-system. */
#define GDISP_NEED_VALIDATION	TRUE
#define GDISP_NEED_CLIP			TRUE
#define GDISP_NEED_CIRCLE       TRUE

/* Features for the GWIN subsystem. */
//#define GWIN_NEED_GL3D          TRUE


#endif /* _GFXCONF_H */
