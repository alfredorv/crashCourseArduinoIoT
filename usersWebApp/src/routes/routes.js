const { Router } = require('express');
const { getUsers, createUser, getUserById, deleteUserById, updateUser } = require('../controllers/index.controller');

const usersEndpoint = '/users'

const router = Router();

router.get(usersEndpoint, getUsers);
router.get(usersEndpoint + '/:id', getUserById);
router.post(usersEndpoint, createUser);
router.delete(usersEndpoint + '/:id', deleteUserById);
router.put(usersEndpoint + '/:id', updateUser);

module.exports = router;