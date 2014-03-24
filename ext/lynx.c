
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "lynx.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"

zend_class_entry *lynx_dbal_connection_ce;
zend_class_entry *lynx_dbal_driver_pdo_ce;
zend_class_entry *lynx_orm_entitymanager_ce;
zend_class_entry *lynx_orm_exception_ce;
zend_class_entry *lynx_orm_query_ce;
zend_class_entry *lynx_orm_querybuilder_ce;
zend_class_entry *lynx_orm_sqlbuilder_ce;
zend_class_entry *lynx_orm_unitofwork_ce;

ZEND_DECLARE_MODULE_GLOBALS(lynx)

static PHP_MINIT_FUNCTION(lynx)
{
#if PHP_VERSION_ID < 50500
	const char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		char *tmp = calloc(strlen(old_lc_all)+1, 1);
		memcpy(tmp, old_lc_all, strlen(old_lc_all));
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(Lynx_DBAL_Connection);
	ZEPHIR_INIT(Lynx_DBAL_Driver_Pdo);
	ZEPHIR_INIT(Lynx_ORM_EntityManager);
	ZEPHIR_INIT(Lynx_ORM_Exception);
	ZEPHIR_INIT(Lynx_ORM_Query);
	ZEPHIR_INIT(Lynx_ORM_QueryBuilder);
	ZEPHIR_INIT(Lynx_ORM_SqlBuilder);
	ZEPHIR_INIT(Lynx_ORM_UnitOfWork);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(lynx)
{

	assert(ZEPHIR_GLOBAL(function_cache) == NULL);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_zephir_globals *zephir_globals TSRMLS_DC)
{

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache options */
	zephir_globals->function_cache = NULL;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;


}

static PHP_RINIT_FUNCTION(lynx)
{

	php_zephir_init_globals(ZEPHIR_VGLOBAL TSRMLS_CC);
	//lynx_init_interned_strings(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(lynx)
{

	if (ZEPHIR_GLOBAL(start_memory) != NULL) {
		zephir_clean_restore_stack(TSRMLS_C);
	}

	if (ZEPHIR_GLOBAL(function_cache) != NULL) {
		zend_hash_destroy(ZEPHIR_GLOBAL(function_cache));
		FREE_HASHTABLE(ZEPHIR_GLOBAL(function_cache));
		ZEPHIR_GLOBAL(function_cache) = NULL;
	}

	return SUCCESS;
}

static PHP_MINFO_FUNCTION(lynx)
{
	php_info_print_table_start();
	php_info_print_table_header(2, PHP_LYNX_NAME, "enabled");
	php_info_print_table_row(2, "Version", PHP_LYNX_VERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(lynx)
{
	zephir_memory_entry *start;

	php_zephir_init_globals(lynx_globals TSRMLS_CC);

	/* Start Memory Frame */
	start = (zephir_memory_entry *) pecalloc(1, sizeof(zephir_memory_entry), 1);
	start->addresses       = pecalloc(16, sizeof(zval*), 1);
	start->capacity        = 16;
	start->hash_addresses  = pecalloc(4, sizeof(zval*), 1);
	start->hash_capacity   = 4;

	lynx_globals->start_memory = start;

	/* Global Constants */
	ALLOC_PERMANENT_ZVAL(lynx_globals->global_false);
	INIT_PZVAL(lynx_globals->global_false);
	ZVAL_FALSE(lynx_globals->global_false);
	Z_ADDREF_P(lynx_globals->global_false);

	ALLOC_PERMANENT_ZVAL(lynx_globals->global_true);
	INIT_PZVAL(lynx_globals->global_true);
	ZVAL_TRUE(lynx_globals->global_true);
	Z_ADDREF_P(lynx_globals->global_true);

	ALLOC_PERMANENT_ZVAL(lynx_globals->global_null);
	INIT_PZVAL(lynx_globals->global_null);
	ZVAL_NULL(lynx_globals->global_null);
	Z_ADDREF_P(lynx_globals->global_null);

}

static PHP_GSHUTDOWN_FUNCTION(lynx)
{
	assert(lynx_globals->start_memory != NULL);

	pefree(lynx_globals->start_memory->hash_addresses, 1);
	pefree(lynx_globals->start_memory->addresses, 1);
	pefree(lynx_globals->start_memory, 1);
	lynx_globals->start_memory = NULL;
}

zend_module_entry lynx_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_LYNX_EXTNAME,
	NULL,
	PHP_MINIT(lynx),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(lynx),
#else
	NULL,
#endif
	PHP_RINIT(lynx),
	PHP_RSHUTDOWN(lynx),
	PHP_MINFO(lynx),
	PHP_LYNX_VERSION,
	ZEND_MODULE_GLOBALS(lynx),
	PHP_GINIT(lynx),
	PHP_GSHUTDOWN(lynx),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_LYNX
ZEND_GET_MODULE(lynx)
#endif
