/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\DBAL\Platform;

class Pgsql
{
    inline public function wrap(id)
    {
        return id;
    }
}
