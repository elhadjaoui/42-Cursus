  <?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'WORD' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', 'root' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         ',9V~jSM&.=&G/n6UlYJy#szy]&8>rvNAilb?~XD8}deT5MX)eMg1r8QKt*DTLl]*' );
define( 'SECURE_AUTH_KEY',  '8g/KrsW$va0&hCck3aSyORt~M<[u!gJ#ktHrjLQRD5w,ykpo&a4cCskg1A+L/55P' );
define( 'LOGGED_IN_KEY',    'y7/4JtChaP5h+(q,WAnhWFyF42?-kU/bVOd/Dk,>FC:9s|:!B0x7B^,79E&XLM|X' );
define( 'NONCE_KEY',        '*-n2ju%qeN`jH`+sUQ6,VS^H5K_RbyS:-1DnE@.;vL,c?oeB(GEqvnY#wG|KcJ6B' );
define( 'AUTH_SALT',        '~VHug2m0Sy<[sJ)K3* _KV~t)q?~,U_AG$IQo]]Ba%D?<m8<vh+|U+C{p,H2{=>g' );
define( 'SECURE_AUTH_SALT', 'D-eye6hhPLZZU]JUUXkz~N.bpP-mO>=x_Cxg7|v}2pGgC%O9<Jom5p&Ec0v.A}?|' );
define( 'LOGGED_IN_SALT',   'PUp>Dq1Hppdd}^8]Me1e+S:eXPh@I8_M{!w0::~x;u*U(Ht.G~5l}Fxc~ACmt>(F' );
define( 'NONCE_SALT',       '+Z]UMq>Itq-:PJj25[H|S5S) *{k4 ~.Lo9Adt*~+}B)_2BEAi h$z<Ae={pHzYj' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );

