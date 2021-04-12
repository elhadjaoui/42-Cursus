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
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'WORDPRESS' );

/** MySQL database username */
define( 'DB_USER', 'lorus' );

/** MySQL database password */
define( 'DB_PASSWORD', 'lorus' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql-service' );

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
define( 'AUTH_KEY',         'JzR z%?tTDDsbWx&2!xHrojCFxA:(RY,K8;joR%>ktrpAL{[Ka3fvOjE@|_YF#fx' );
define( 'SECURE_AUTH_KEY',  'K{4w:Uy[sSn U[KMj-<=`k#L@fTIRA5_yY6wa#9^]oO(^Wk9DsLM;T?E~#53<f n' );
define( 'LOGGED_IN_KEY',    '.j|BL}TjClq}4*_muon9)z|=Nv(B?t@?R8[OWEhJ>uy;uE/g$[!oe!`YdRJg6xZ4' );
define( 'NONCE_KEY',        '[K)1sc#3v!Zx^zp#8zm>IqQ@JD?8K%5@s}@VP;R/jup~Zo4OB<2rYdL a<>ju?!O' );
define( 'AUTH_SALT',        '( (Vg(8G`F:Tm B2ouy8|0VZ8$/{WOo*DyQD)gcR,89xi?^TwTTt)-I:V$y^xlR6' );
define( 'SECURE_AUTH_SALT', 'Q@PmZ%.[O3_y_i=TKD)~YMW ,yFF4z]cX2<mD48guZX%EM6.wmcV[WRPSGQ&ZN,d' );
define( 'LOGGED_IN_SALT',   'OQ3]#y9td@<YnotC9oy{qYZe>Zg8V; Tm|4Opkj<&>sSIO2i 4TPHR:)-SJ)9Pu<' );
define( 'NONCE_SALT',       '@iz/(KvXc6?MGfzWar!-Q@ni=&b15fl=_$/KF9_R;&oyn5bW9;`JCRW7Y 2E,6X:' );

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
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';