/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

use Lynx\DBAL\Connection;
use Lynx\Stdlib\Events\Manager as EventsManager;

class EntityManager
{
    /**
     * @var UnitOfWork
     */
    protected unitOfWork {get};

    protected connection {get};

    protected modelsManager {get};

    protected eventManager {get};

    protected repositories;

    protected configuration {get};

    public function __construct(<Connection> connection, <Configuration> configuration, <EventsManager> eventManager)
    {
        let this->eventManager = eventManager;
        let this->connection = connection;
        let this->configuration = configuration;

        let this->unitOfWork = new UnitOfWork(this);
        let this->modelsManager = new ModelsManager(this);
    }

    public function flush(var entity)
    {

    }

    public function remove(object! entity)
    {

    }

    public function beginTransaction()
    {
        this->connection->beginTransaction();
    }

    public function commit()
    {
        this->connection->commit();
    }


    public function rollback()
    {
        this->connection->rollback();
    }

    public function getRepository(string! entityName) -> <EntityRepository>
    {
        var repository;

        if fetch repository, this->repositories[entityName] {
            return repository;
        }

        let this->repositories[entityName] = new EntityRepository(this, this->modelsManager->get(entityName));
        return this->repositories[entityName];
    }

    public function createQueryBuilder() -> <QueryBuilder>
    {
        return new QueryBuilder(this);
    }

    public function createQuery(var sql) -> <Query>
    {
        return new Query(sql, this);
    }
}
