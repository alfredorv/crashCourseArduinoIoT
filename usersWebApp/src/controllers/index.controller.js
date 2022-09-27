const { Pool } = require('pg');

const listUsersSQL = 'SELECT * FROM users';
const listUserByIdSQL = 'SELECT * FROM users WHERE id = $1';
const createUserSQL = 'INSERT INTO users (name, email) VALUES ($1, $2)';
const deleteUserByIdSQL = 'DELETE FROM users WHERE id = $1';
const updateUserByIdSQL = 'UPDATE users SET name = $1, email = $2 WHERE id = $3';

const pool = new Pool({
  host: 'localhost',
  user: 'alfredorenteria',
  password: '',
  database: 'users_api',
  port: '5432'
});

const getUsers = async (req, res) => {
  const response = await pool.query(listUsersSQL);
  res.status(200).json(response.rows);
}

const getUserById = async (req, res) => {
  const response = await pool.query(listUserByIdSQL, [req.params.id]);
  res.status(200).json(response.rows);
}

const createUser = async (req, res) => {
  const { name, email } = req.body;
  const response = await pool.query(createUserSQL, [name, email]);
  res.json({
    message: 'Usuario creado exitosamente!',
    body: {
      user: { name, email }
    }
  });
}

const deleteUserById = async (req, res) => {
  const response = await pool.query(deleteUserByIdSQL, [req.params.id]);
  res.status(200).json(response.rows);
}

const updateUser = async (req, res) => {
  const { name, email } = req.body;
  const response = await pool.query(updateUserByIdSQL, [name, email, req.params.id]);
  res.status(200).json(response.rows);
}

module.exports = {
  getUsers,
  createUser,
  getUserById,
  deleteUserById,
  updateUser
}