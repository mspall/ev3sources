
/* File: eggdbusbus.h
 *
 * Generated by eggdbus-binding-tool 0.6. Do not edit.
 */

#ifndef __EGG_DBUS_BUS_H
#define __EGG_DBUS_BUS_H

#include <glib-object.h>
#include <gio/gio.h>
#include <eggdbus/eggdbustypes.h>
#include <eggdbus/eggdbusinterface.h>
#include <eggdbus/eggdbusinterfaceproxy.h>
#include <eggdbus/eggdbusrequestnameflags.h>
#include <eggdbus/eggdbusrequestnamereply.h>
#include <eggdbus/eggdbusreleasenamereply.h>
#include <eggdbus/eggdbusstartservicebynamereply.h>

G_BEGIN_DECLS

#define EGG_DBUS_TYPE_BUS         (egg_dbus_bus_get_type())
#define EGG_DBUS_BUS(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), EGG_DBUS_TYPE_BUS, EggDBusBus))
#define EGG_DBUS_IS_BUS(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), EGG_DBUS_TYPE_BUS))
#define EGG_DBUS_BUS_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE((o), EGG_DBUS_TYPE_BUS, EggDBusBusIface))

#if 0
typedef struct _EggDBusBus EggDBusBus; /* Dummy typedef */
#endif
typedef struct _EggDBusBusIface EggDBusBusIface;

/**
 * EGG_DBUS_QUERY_INTERFACE_BUS:
 * @object_proxy: A #EggDBusObjectProxy.
 *
 * Convenience macro to get an interface proxy for the remote object represented
 * by @object_proxy. See egg_dbus_object_proxy_query_interface() for details.
 *
 * Returns: An instance derived from #EggDBusInterfaceProxy that implements the
 *          #EggDBusBus interface. This instance can be used to access the
 *          <link linkend="eggdbus-interface-org.freedesktop.DBus">org.freedesktop.DBus</link> D-Bus interface on the remote
 *          object represented by @object_proxy. Do not ref or unref the returned instance,
 *          it is owned by @object_proxy.
 */
#define EGG_DBUS_QUERY_INTERFACE_BUS(object_proxy) (EGG_DBUS_BUS (egg_dbus_object_proxy_query_interface (object_proxy, EGG_DBUS_TYPE_BUS)))

/**
 * EggDBusBusIface:
 * @g_iface: The parent interface.
 * @handle_hello: Before an application is able to send messages to other applications it must invoke this method on the message bus to obtain a unique name. If an application without a unique name tries to send a message to another application, or a message to the message bus itself that isn't the egg_dbus_bus_hello() method, it will be disconnected from the bus. There is no corresponding <emphasis>disconnect</emphasis> request; if a client wishes to disconnect from the bus, it simply closes the socket (or other communication channel).
 * @handle_request_name: This method call should be invoked on the <literal>org.freedesktop.DBus</literal> name to request the message bus to assign the given name to the method caller. Each name maintains a queue of possible owners, where the head of the queue is the primary or current owner of the name. Each potential owner in the queue maintains the %EGG_DBUS_REQUEST_NAME_FLAGS_ALLOW_REPLACEMENT and %EGG_DBUS_REQUEST_NAME_FLAGS_DO_NOT_QUEUE settings from its latest egg_dbus_bus_request_name() call. See the D-Bus specification for more details.
 * @handle_release_name: This method call should be invoked on the <literal>org.freedesktop.DBus</literal> name to request the message bus to release the method caller's claim to the given name. If the caller is the primary owner, a new primary owner will be selected from the queue if any other owners are waiting. If the caller is waiting in the queue for the name, the caller will removed from the queue and will not be made an owner of the name if it later becomes available. If there are no other owners in the queue for the name, it will be removed from the bus entirely.
 * @handle_start_service_by_name: Tries to launch the executable associated with @name. See the D-Bus specification for more details on service activation.
 * @handle_update_activation_environment: Normally, session bus activated services inherit the environment of the bus daemon.  This method adds to or modifies that environment when activating services. Some bus instances, such as the standard system bus, may disable access to this method for some or all callers.
 * @handle_name_has_owner: Checks if the specified name exists (currently has an owner).
 * @handle_list_names: Returns a list of all currently-owned names on the bus.
 * @handle_list_activatable_names: Returns a list of all names that can be activated on the bus.
 * @handle_add_match: Adds a match rule to match messages going through the message bus. If the bus does not have enough resources the %org.freedesktop.DBus.Error.OOM error is returned. See the D-Bus specification for more information about match rules.
 * @handle_remove_match: Removes the first rule that matches. If the rule is not found the %org.freedesktop.DBus.Error.MatchRuleNotFound  error is returned. See the D-Bus specification for more information about match rules.
 * @handle_get_name_owner: Returns the unique connection name of the primary owner of the name given. If the requested name doesn't have an owner, returns a %org.freedesktop.DBus.Error.NameHasNoOwner error.
 * @handle_list_queued_owners: Lists the names waiting in queue to own @name.
 * @handle_get_connection_unix_user: Returns the UNIX user id of the process connected to the server. If unable to determine it, a %org.freedesktop.DBus.Error.Failed error is returned.
 * @handle_get_connection_unix_process_id: Returns the UNIX process id of the process connected to the server. If unable to determine it, a %org.freedesktop.DBus.Error.Failed error is returned.
 * @handle_get_adt_audit_session_data: Returns the Solaris/ADT auditing data of the process connected to the server. If unable to determine it, a %org.freedesktop.DBus.Error.AdtAuditDataUnknown error is returned.
 * @handle_get_connection_se_linux_security_context: Returns the SELinux security context of the process connected to the server. If unable to determine it, a %org.freedesktop.DBus.Error.SELinuxSecurityContextUnknown error is returned.
 * @handle_reload_config: Asks the message bus to reload configuration files.
 * @handle_get_id: Gets the unique ID of the bus. The unique ID here is shared among all addresses the bus daemon is listening on (TCP, UNIX domain socket, etc.). Each address the bus is listening on also has its own unique ID. The per-bus and per-address IDs are not related. For a desktop session bus, the bus ID can be used as a way to uniquely identify a user's session. See the D-Bus specification for more information about unique IDs.
 *
 * Interface VTable for implementing the <link linkend="eggdbus-interface-org.freedesktop.DBus">org.freedesktop.DBus</link> D-Bus interface.
 */
struct _EggDBusBusIface
{
  EggDBusInterfaceIface g_iface;

  void (* handle_hello) (
      EggDBusBus *instance,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_request_name) (
      EggDBusBus *instance,
      const gchar *name,
      EggDBusRequestNameFlags flags,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_release_name) (
      EggDBusBus *instance,
      const gchar *name,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_start_service_by_name) (
      EggDBusBus *instance,
      const gchar *name,
      guint flags,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_update_activation_environment) (
      EggDBusBus *instance,
      EggDBusHashMap *env_hash,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_name_has_owner) (
      EggDBusBus *instance,
      const gchar *name,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_list_names) (
      EggDBusBus *instance,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_list_activatable_names) (
      EggDBusBus *instance,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_add_match) (
      EggDBusBus *instance,
      const gchar *rule,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_remove_match) (
      EggDBusBus *instance,
      const gchar *rule,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_get_name_owner) (
      EggDBusBus *instance,
      const gchar *name,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_list_queued_owners) (
      EggDBusBus *instance,
      const gchar *name,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_get_connection_unix_user) (
      EggDBusBus *instance,
      const gchar *name,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_get_connection_unix_process_id) (
      EggDBusBus *instance,
      const gchar *name,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_get_adt_audit_session_data) (
      EggDBusBus *instance,
      const gchar *name,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_get_connection_se_linux_security_context) (
      EggDBusBus *instance,
      const gchar *name,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_reload_config) (
      EggDBusBus *instance,
      EggDBusMethodInvocation *method_invocation);

  void (* handle_get_id) (
      EggDBusBus *instance,
      EggDBusMethodInvocation *method_invocation);
};

GType egg_dbus_bus_get_type (void) G_GNUC_CONST;

gboolean egg_dbus_bus_hello_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    gchar **out_assigned_name,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_request_name_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    EggDBusRequestNameFlags flags,
    EggDBusRequestNameReply *out_value,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_release_name_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    EggDBusReleaseNameReply *out_value,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_start_service_by_name_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    guint flags,
    EggDBusStartServiceByNameReply *out_value,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_update_activation_environment_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    EggDBusHashMap *env_hash,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_name_has_owner_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    gboolean *out_has_owner,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_list_names_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    gchar ***out_names,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_list_activatable_names_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    gchar ***out_activatable_names,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_add_match_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *rule,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_remove_match_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *rule,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_get_name_owner_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    gchar **out_unique_name,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_list_queued_owners_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    gchar ***out_queued_owners,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_get_connection_unix_user_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    uid_t *out_uid,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_get_connection_unix_process_id_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    pid_t *out_pid,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_get_adt_audit_session_data_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    EggDBusArraySeq **out_data,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_get_connection_se_linux_security_context_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    EggDBusArraySeq **out_security_context,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_reload_config_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    GCancellable *cancellable,
    GError **error);

gboolean egg_dbus_bus_get_id_sync (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    gchar **out_unique_id,
    GCancellable *cancellable,
    GError **error);

guint egg_dbus_bus_hello (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_hello_finish (
    EggDBusBus *instance,
    gchar **out_assigned_name,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_request_name (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    EggDBusRequestNameFlags flags,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_request_name_finish (
    EggDBusBus *instance,
    EggDBusRequestNameReply *out_value,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_release_name (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_release_name_finish (
    EggDBusBus *instance,
    EggDBusReleaseNameReply *out_value,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_start_service_by_name (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    guint flags,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_start_service_by_name_finish (
    EggDBusBus *instance,
    EggDBusStartServiceByNameReply *out_value,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_update_activation_environment (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    EggDBusHashMap *env_hash,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_update_activation_environment_finish (
    EggDBusBus *instance,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_name_has_owner (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_name_has_owner_finish (
    EggDBusBus *instance,
    gboolean *out_has_owner,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_list_names (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_list_names_finish (
    EggDBusBus *instance,
    gchar ***out_names,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_list_activatable_names (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_list_activatable_names_finish (
    EggDBusBus *instance,
    gchar ***out_activatable_names,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_add_match (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *rule,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_add_match_finish (
    EggDBusBus *instance,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_remove_match (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *rule,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_remove_match_finish (
    EggDBusBus *instance,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_get_name_owner (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_get_name_owner_finish (
    EggDBusBus *instance,
    gchar **out_unique_name,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_list_queued_owners (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_list_queued_owners_finish (
    EggDBusBus *instance,
    gchar ***out_queued_owners,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_get_connection_unix_user (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_get_connection_unix_user_finish (
    EggDBusBus *instance,
    uid_t *out_uid,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_get_connection_unix_process_id (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_get_connection_unix_process_id_finish (
    EggDBusBus *instance,
    pid_t *out_pid,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_get_adt_audit_session_data (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_get_adt_audit_session_data_finish (
    EggDBusBus *instance,
    EggDBusArraySeq **out_data,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_get_connection_se_linux_security_context (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    const gchar *name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_get_connection_se_linux_security_context_finish (
    EggDBusBus *instance,
    EggDBusArraySeq **out_security_context,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_reload_config (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_reload_config_finish (
    EggDBusBus *instance,
    GAsyncResult *res,
    GError **error);

guint egg_dbus_bus_get_id (
    EggDBusBus *instance,
    EggDBusCallFlags call_flags,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean egg_dbus_bus_get_id_finish (
    EggDBusBus *instance,
    gchar **out_unique_id,
    GAsyncResult *res,
    GError **error);

void egg_dbus_bus_handle_hello_finish (
    EggDBusMethodInvocation *method_invocation,
    const gchar *out_assigned_name);

void egg_dbus_bus_handle_request_name_finish (
    EggDBusMethodInvocation *method_invocation,
    EggDBusRequestNameReply out_value);

void egg_dbus_bus_handle_release_name_finish (
    EggDBusMethodInvocation *method_invocation,
    EggDBusReleaseNameReply out_value);

void egg_dbus_bus_handle_start_service_by_name_finish (
    EggDBusMethodInvocation *method_invocation,
    EggDBusStartServiceByNameReply out_value);

void egg_dbus_bus_handle_update_activation_environment_finish (
    EggDBusMethodInvocation *method_invocation);

void egg_dbus_bus_handle_name_has_owner_finish (
    EggDBusMethodInvocation *method_invocation,
    gboolean out_has_owner);

void egg_dbus_bus_handle_list_names_finish (
    EggDBusMethodInvocation *method_invocation,
    gchar **out_names);

void egg_dbus_bus_handle_list_activatable_names_finish (
    EggDBusMethodInvocation *method_invocation,
    gchar **out_activatable_names);

void egg_dbus_bus_handle_add_match_finish (
    EggDBusMethodInvocation *method_invocation);

void egg_dbus_bus_handle_remove_match_finish (
    EggDBusMethodInvocation *method_invocation);

void egg_dbus_bus_handle_get_name_owner_finish (
    EggDBusMethodInvocation *method_invocation,
    const gchar *out_unique_name);

void egg_dbus_bus_handle_list_queued_owners_finish (
    EggDBusMethodInvocation *method_invocation,
    gchar **out_queued_owners);

void egg_dbus_bus_handle_get_connection_unix_user_finish (
    EggDBusMethodInvocation *method_invocation,
    uid_t out_uid);

void egg_dbus_bus_handle_get_connection_unix_process_id_finish (
    EggDBusMethodInvocation *method_invocation,
    pid_t out_pid);

void egg_dbus_bus_handle_get_adt_audit_session_data_finish (
    EggDBusMethodInvocation *method_invocation,
    EggDBusArraySeq *out_data);

void egg_dbus_bus_handle_get_connection_se_linux_security_context_finish (
    EggDBusMethodInvocation *method_invocation,
    EggDBusArraySeq *out_security_context);

void egg_dbus_bus_handle_reload_config_finish (
    EggDBusMethodInvocation *method_invocation);

void egg_dbus_bus_handle_get_id_finish (
    EggDBusMethodInvocation *method_invocation,
    const gchar *out_unique_id);

void egg_dbus_bus_emit_signal_name_owner_changed (
    EggDBusBus *instance,
    const gchar *destination,
    const gchar *name,
    const gchar *old_owner,
    const gchar *new_owner);

void egg_dbus_bus_emit_signal_name_lost (
    EggDBusBus *instance,
    const gchar *destination,
    const gchar *name);

void egg_dbus_bus_emit_signal_name_acquired (
    EggDBusBus *instance,
    const gchar *destination,
    const gchar *name);

G_END_DECLS

#endif /* __EGG_DBUS_BUS_H */