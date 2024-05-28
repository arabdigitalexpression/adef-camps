# Drupal Site Setup with Docker and Docker Compose

This project sets up a Drupal site using Docker and Docker Compose. The instructions below will guide you through the process of installing Docker and Docker Compose on various Linux distributions, and then how to use them to run this Drupal site.

## Prerequisites

- Docker
- Docker Compose

## Installing Docker

### Ubuntu

```bash
# Update the package list
sudo apt-get update

# Install necessary packages
sudo apt-get install -y apt-transport-https ca-certificates curl software-properties-common

# Add Docker’s official GPG key
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

# Add the Docker APT repository
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"

# Update the package list again
sudo apt-get update

# Install Docker CE
sudo apt-get install -y docker-ce

# Start Docker service
sudo systemctl start docker

# Enable Docker to start at boot
sudo systemctl enable docker
```

### CentOS

```bash
# Update the package list
sudo yum update -y

# Install necessary packages
sudo yum install -y yum-utils device-mapper-persistent-data lvm2

# Add the Docker repository
sudo yum-config-manager --add-repo https://download.docker.com/linux/centos/docker-ce.repo

# Install Docker CE
sudo yum install -y docker-ce

# Start Docker service
sudo systemctl start docker

# Enable Docker to start at boot
sudo systemctl enable docker
```

### Fedora

```bash
# Update the package list
sudo dnf update -y

# Install Docker CE
sudo dnf install -y docker-ce docker-ce-cli containerd.io

# Start Docker service
sudo systemctl start docker

# Enable Docker to start at boot
sudo systemctl enable docker
```

## Installing Docker Compose

### Ubuntu, CentOS, Fedora

```bash
# Download the Docker Compose binary
sudo curl -L "https://github.com/docker/compose/releases/download/1.29.2/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose

# Apply executable permissions to the binary
sudo chmod +x /usr/local/bin/docker-compose

# Verify the installation
docker-compose --version
```

## Important Notes

- **SQL Import**: Any `.sql` file placed in the `db_dumps` directory will be imported into the database specified by the `MYSQL_DATABASE` environment variable. For more information on how MySQL imports `.sql` files, visit the [official MySQL Docker Hub page](https://hub.docker.com/_/mysql).
- **.gitignore**: Ensure that `.sql` files are excluded from your Git repository by adding them to your `.gitignore` file:

  ```plaintext
  db_dumps/*.sql
  ```

## Running the Drupal Site

1. **Clone the Repository**

   ```bash
   git clone https://github.com/yourusername/your-repo.git
   cd your-repo
   ```

2. **Create and Configure `.env` File**

   Create a `.env` file in the root of the project (you can copy .env.example) and add the following content, replacing the values as necessary:

   ```env
   MYSQL_DATABASE=drupal
   MYSQL_USER=drupal
   MYSQL_PASSWORD=drupal
   MYSQL_HOST=db
   HASH_SALT=your_hash_salt_here
   ```

3. **Build and Start the Containers**

   ```bash
   docker-compose up --build -d
   ```

4. **Access the Drupal Site**

   Open your web browser and navigate to `http://localhost:8080` (or the appropriate port) to access your Drupal site.

## Project Structure

```
.
├── .env
├── create_settings.sh
├── db_dumps
│   └── campsystem_2017-08-22.sql
├── docker-compose.yml
├── Dockerfile.drupal
├── Dockerfile.db
└── README.md
```

- **.env**: Environment variables for the database configuration.
- **create_settings.sh**: Script to create the `settings.php` file with database configuration.
- **db_dumps**: Directory containing the MySQL database dump file (if you have one).
- **docker-compose.yml**: Docker Compose configuration file.
- **Dockerfile.drupal**: Dockerfile to set up the Drupal container.
- **Dockerfile.db**: Dockerfile to set up the MySQL container.
- **README.md**: This file.

## Troubleshooting

- If you encounter permission issues, ensure that your user is added to the Docker group:
  
  ```bash
  sudo usermod -aG docker $USER
  ```

  Then log out and log back in.

- Verify that the containers are running:
  
  ```bash
  docker-compose ps
  ```

- Check the logs for any errors:
  
  ```bash
  docker-compose logs
  ```

## Conclusion

This guide should help you set up and run a Drupal site using Docker and Docker Compose on various Linux distributions. If you encounter any issues, please refer to the official Docker and Docker Compose documentation for further assistance.
