
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_Stdlib_Events_EventsManager) {

	ZEPHIR_REGISTER_INTERFACE(Lynx\\Stdlib\\Events, EventsManager, lynx, stdlib_events_eventsmanager, lynx_stdlib_events_eventsmanager_method_entry);

	return SUCCESS;

}

/**
 * Attach a listener to the events manager
 *
 * @param string eventType
 * @param object handler
 */
ZEPHIR_DOC_METHOD(Lynx_Stdlib_Events_EventsManager, attach);

/**
 * Removes all events from the EventsManager
 *
 * @param string type
 */
ZEPHIR_DOC_METHOD(Lynx_Stdlib_Events_EventsManager, dettachAll);

/**
 * Fires a event in the events manager causing that the acive listeners will be notified about it
 *
 * @param string eventType
 * @param object source
 * @param mixed  data
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Lynx_Stdlib_Events_EventsManager, fire);

/**
 * Returns all the attached listeners of a certain type
 *
 * @param string type
 * @return array
 */
ZEPHIR_DOC_METHOD(Lynx_Stdlib_Events_EventsManager, getListeners);

