/* spice-controller.h generated by valac 0.26.1, the Vala compiler, do not modify */


#ifndef __SPICE_CONTROLLER_H__
#define __SPICE_CONTROLLER_H__

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <spice/controller_prot.h>
#include <gio/gio.h>

G_BEGIN_DECLS


#define SPICE_CTRL_TYPE_MENU_ITEM (spice_ctrl_menu_item_get_type ())
#define SPICE_CTRL_MENU_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SPICE_CTRL_TYPE_MENU_ITEM, SpiceCtrlMenuItem))
#define SPICE_CTRL_MENU_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SPICE_CTRL_TYPE_MENU_ITEM, SpiceCtrlMenuItemClass))
#define SPICE_CTRL_IS_MENU_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SPICE_CTRL_TYPE_MENU_ITEM))
#define SPICE_CTRL_IS_MENU_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SPICE_CTRL_TYPE_MENU_ITEM))
#define SPICE_CTRL_MENU_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SPICE_CTRL_TYPE_MENU_ITEM, SpiceCtrlMenuItemClass))

typedef struct _SpiceCtrlMenuItem SpiceCtrlMenuItem;
typedef struct _SpiceCtrlMenuItemClass SpiceCtrlMenuItemClass;
typedef struct _SpiceCtrlMenuItemPrivate SpiceCtrlMenuItemPrivate;

#define SPICE_CTRL_TYPE_MENU (spice_ctrl_menu_get_type ())
#define SPICE_CTRL_MENU(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SPICE_CTRL_TYPE_MENU, SpiceCtrlMenu))
#define SPICE_CTRL_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SPICE_CTRL_TYPE_MENU, SpiceCtrlMenuClass))
#define SPICE_CTRL_IS_MENU(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SPICE_CTRL_TYPE_MENU))
#define SPICE_CTRL_IS_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SPICE_CTRL_TYPE_MENU))
#define SPICE_CTRL_MENU_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SPICE_CTRL_TYPE_MENU, SpiceCtrlMenuClass))

typedef struct _SpiceCtrlMenu SpiceCtrlMenu;
typedef struct _SpiceCtrlMenuClass SpiceCtrlMenuClass;
typedef struct _SpiceCtrlMenuPrivate SpiceCtrlMenuPrivate;

#define SPICE_CTRL_TYPE_CONTROLLER (spice_ctrl_controller_get_type ())
#define SPICE_CTRL_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SPICE_CTRL_TYPE_CONTROLLER, SpiceCtrlController))
#define SPICE_CTRL_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SPICE_CTRL_TYPE_CONTROLLER, SpiceCtrlControllerClass))
#define SPICE_CTRL_IS_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SPICE_CTRL_TYPE_CONTROLLER))
#define SPICE_CTRL_IS_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SPICE_CTRL_TYPE_CONTROLLER))
#define SPICE_CTRL_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SPICE_CTRL_TYPE_CONTROLLER, SpiceCtrlControllerClass))

typedef struct _SpiceCtrlController SpiceCtrlController;
typedef struct _SpiceCtrlControllerClass SpiceCtrlControllerClass;
typedef struct _SpiceCtrlControllerPrivate SpiceCtrlControllerPrivate;

#define SPICE_CTRL_TYPE_FOREIGN_MENU (spice_ctrl_foreign_menu_get_type ())
#define SPICE_CTRL_FOREIGN_MENU(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SPICE_CTRL_TYPE_FOREIGN_MENU, SpiceCtrlForeignMenu))
#define SPICE_CTRL_FOREIGN_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SPICE_CTRL_TYPE_FOREIGN_MENU, SpiceCtrlForeignMenuClass))
#define SPICE_CTRL_IS_FOREIGN_MENU(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SPICE_CTRL_TYPE_FOREIGN_MENU))
#define SPICE_CTRL_IS_FOREIGN_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SPICE_CTRL_TYPE_FOREIGN_MENU))
#define SPICE_CTRL_FOREIGN_MENU_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SPICE_CTRL_TYPE_FOREIGN_MENU, SpiceCtrlForeignMenuClass))

typedef struct _SpiceCtrlForeignMenu SpiceCtrlForeignMenu;
typedef struct _SpiceCtrlForeignMenuClass SpiceCtrlForeignMenuClass;
typedef struct _SpiceCtrlForeignMenuPrivate SpiceCtrlForeignMenuPrivate;

struct _SpiceCtrlMenuItem {
	GObject parent_instance;
	SpiceCtrlMenuItemPrivate * priv;
	SpiceCtrlMenu* submenu;
	gint parent_id;
	gint id;
	gchar* text;
	gchar* accel;
	unsigned int flags;
};

struct _SpiceCtrlMenuItemClass {
	GObjectClass parent_class;
};

typedef enum  {
	SPICE_CTRL_ERROR_VALUE
} SpiceCtrlError;
#define SPICE_CTRL_ERROR spice_ctrl_error_quark ()
struct _SpiceCtrlMenu {
	GObject parent_instance;
	SpiceCtrlMenuPrivate * priv;
	GList* items;
};

struct _SpiceCtrlMenuClass {
	GObjectClass parent_class;
};

struct _SpiceCtrlController {
	GObject parent_instance;
	SpiceCtrlControllerPrivate * priv;
};

struct _SpiceCtrlControllerClass {
	GObjectClass parent_class;
};

struct _SpiceCtrlForeignMenu {
	GObject parent_instance;
	SpiceCtrlForeignMenuPrivate * priv;
};

struct _SpiceCtrlForeignMenuClass {
	GObjectClass parent_class;
};


GType spice_ctrl_menu_item_get_type (void) G_GNUC_CONST;
GType spice_ctrl_menu_get_type (void) G_GNUC_CONST;
SpiceCtrlMenuItem* spice_ctrl_menu_item_new (gint id, const gchar* text, unsigned int flags);
SpiceCtrlMenuItem* spice_ctrl_menu_item_construct (GType object_type, gint id, const gchar* text, unsigned int flags);
GQuark spice_ctrl_error_quark (void);
SpiceCtrlMenuItem* spice_ctrl_menu_item_new_from_string (const gchar* str, GError** error);
SpiceCtrlMenuItem* spice_ctrl_menu_item_construct_from_string (GType object_type, const gchar* str, GError** error);
gchar* spice_ctrl_menu_item_to_string (SpiceCtrlMenuItem* self);
SpiceCtrlMenu* spice_ctrl_menu_find_id (SpiceCtrlMenu* self, gint id);
SpiceCtrlMenu* spice_ctrl_menu_new_from_string (const gchar* str);
SpiceCtrlMenu* spice_ctrl_menu_construct_from_string (GType object_type, const gchar* str);
gchar* spice_ctrl_menu_to_string (SpiceCtrlMenu* self);
SpiceCtrlMenu* spice_ctrl_menu_new (void);
SpiceCtrlMenu* spice_ctrl_menu_construct (GType object_type);
GType spice_ctrl_controller_get_type (void) G_GNUC_CONST;
void spice_ctrl_controller_menu_item_click_msg (SpiceCtrlController* self, gint32 item_id);
void spice_ctrl_controller_send_msg (SpiceCtrlController* self, guint8* p, int p_length1, GAsyncReadyCallback _callback_, gpointer _user_data_);
gboolean spice_ctrl_controller_send_msg_finish (SpiceCtrlController* self, GAsyncResult* _res_, GError** error);
SpiceCtrlController* spice_ctrl_controller_new (void);
SpiceCtrlController* spice_ctrl_controller_construct (GType object_type);
void spice_ctrl_controller_listen (SpiceCtrlController* self, const gchar* addr, GAsyncReadyCallback _callback_, gpointer _user_data_);
void spice_ctrl_controller_listen_finish (SpiceCtrlController* self, GAsyncResult* _res_, GError** error);
const gchar* spice_ctrl_controller_get_host (SpiceCtrlController* self);
guint32 spice_ctrl_controller_get_port (SpiceCtrlController* self);
guint32 spice_ctrl_controller_get_sport (SpiceCtrlController* self);
const gchar* spice_ctrl_controller_get_password (SpiceCtrlController* self);
unsigned int spice_ctrl_controller_get_display_flags (SpiceCtrlController* self);
const gchar* spice_ctrl_controller_get_tls_ciphers (SpiceCtrlController* self);
const gchar* spice_ctrl_controller_get_host_subject (SpiceCtrlController* self);
const gchar* spice_ctrl_controller_get_ca_file (SpiceCtrlController* self);
const gchar* spice_ctrl_controller_get_title (SpiceCtrlController* self);
const gchar* spice_ctrl_controller_get_hotkeys (SpiceCtrlController* self);
gchar** spice_ctrl_controller_get_secure_channels (SpiceCtrlController* self, int* result_length1);
gchar** spice_ctrl_controller_get_disable_channels (SpiceCtrlController* self, int* result_length1);
SpiceCtrlMenu* spice_ctrl_controller_get_menu (SpiceCtrlController* self);
gboolean spice_ctrl_controller_get_enable_smartcard (SpiceCtrlController* self);
gboolean spice_ctrl_controller_get_send_cad (SpiceCtrlController* self);
gchar** spice_ctrl_controller_get_disable_effects (SpiceCtrlController* self, int* result_length1);
guint32 spice_ctrl_controller_get_color_depth (SpiceCtrlController* self);
gboolean spice_ctrl_controller_get_enable_usbredir (SpiceCtrlController* self);
gboolean spice_ctrl_controller_get_enable_usb_autoshare (SpiceCtrlController* self);
const gchar* spice_ctrl_controller_get_usb_filter (SpiceCtrlController* self);
const gchar* spice_ctrl_controller_get_proxy (SpiceCtrlController* self);
GType spice_ctrl_foreign_menu_get_type (void) G_GNUC_CONST;
SpiceCtrlForeignMenu* spice_ctrl_foreign_menu_new (void);
SpiceCtrlForeignMenu* spice_ctrl_foreign_menu_construct (GType object_type);
void spice_ctrl_foreign_menu_menu_item_click_msg (SpiceCtrlForeignMenu* self, gint32 item_id);
void spice_ctrl_foreign_menu_menu_item_checked_msg (SpiceCtrlForeignMenu* self, gint32 item_id, gboolean checked);
void spice_ctrl_foreign_menu_app_activated_msg (SpiceCtrlForeignMenu* self, gboolean activated);
void spice_ctrl_foreign_menu_send_msg (SpiceCtrlForeignMenu* self, guint8* p, int p_length1, GAsyncReadyCallback _callback_, gpointer _user_data_);
gboolean spice_ctrl_foreign_menu_send_msg_finish (SpiceCtrlForeignMenu* self, GAsyncResult* _res_, GError** error);
void spice_ctrl_foreign_menu_listen (SpiceCtrlForeignMenu* self, const gchar* addr, GAsyncReadyCallback _callback_, gpointer _user_data_);
void spice_ctrl_foreign_menu_listen_finish (SpiceCtrlForeignMenu* self, GAsyncResult* _res_, GError** error);
SpiceCtrlMenu* spice_ctrl_foreign_menu_get_menu (SpiceCtrlForeignMenu* self);
const gchar* spice_ctrl_foreign_menu_get_title (SpiceCtrlForeignMenu* self);
void spice_ctrl_input_stream_read (GInputStream* stream, guint8* buffer, int buffer_length1, GAsyncReadyCallback _callback_, gpointer _user_data_);
void spice_ctrl_input_stream_read_finish (GAsyncResult* _res_, GError** error);
void spice_ctrl_output_stream_write (GOutputStream* stream, guint8* buffer, int buffer_length1, GAsyncReadyCallback _callback_, gpointer _user_data_);
void spice_ctrl_output_stream_write_finish (GAsyncResult* _res_, GError** error);


G_END_DECLS

#endif
