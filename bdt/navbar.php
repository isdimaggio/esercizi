<?php

function T_navbar($breadcrumb = null) {
    global $config_navbar;
    ?>
    <nav class="navbar navbar-expand-lg ddcc grayy">
        <div class="container-fluid">
            <a class="alert-link ddc" href="/">
                <img src="icons/logo.png" alt="logo" height="30" style="margin-right: 10px;">
            </a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavDropdown"
                aria-controls="navbarNavDropdown" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarNavDropdown">
                <ul class="navbar-nav">
                    <?php
                    $primo = true;
                    foreach($config_navbar as $top_item){
                        if (F_compare_permissions($top_item['roles'])) {
                            if(isset($top_item['sub'])){
                                ?>
                                <li class="nav-item dropdown ddc <?= $primo ? "dccd" : "" ?>">
                                    <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown"
                                        aria-expanded="false">
                                        <i class='bi bi-<?= $top_item['icon'] ?> spo'></i>
                                        <?= $top_item['name'] ?>
                                    </a>
                                    <ul class="dropdown-menu">
                                        <?php
                                        foreach($top_item['sub'] as $bottom_item){
                                            if (F_compare_permissions($bottom_item['roles'])) {
                                                ?>
                                                <li><a class="dropdown-item" href="<?= $bottom_item['url'] ?>">
                                                    <i class='bi bi-<?= $bottom_item['icon'] ?> spo'></i>
                                                    <?= $bottom_item['name'] ?>
                                                </a></li>
                                                <?php
                                            }
                                        }
                                        ?>
                                    </ul>
                                </li>
                                <?php
                            } else {
                                ?>
                                <li class="nav-item ddc">
                                    <a class="nav-link" href="<?= $top_item['url'] ?>">
                                        <i class='bi bi-<?= $top_item['icon'] ?> spo'></i>
                                        <?= $top_item['name'] ?>
                                    </a>
                                </li>
                                <?php
                            }
                        }
                        $primo = false;
                    }
                    ?>           
                </ul>
            </div>
        </div>
        <div class="flex-shrink-0 dropdown" style='margin-right: 15px'>
          <a href="#" class="d-block link-body-emphasis text-decoration-none dropdown-toggle dccd" style="padding-left: 13px;"
           data-bs-toggle="dropdown" aria-expanded="false">
            <img src="<?= F_userinfo_gravatar() ?>" alt="profile picture" width="30" height="30" class="rounded-circle mtb4">
            <span class="username"><?= F_userinfo_displayname() ?></span>
          </a>
          <ul class="dropdown-menu text-small shadow" style="position: absolute; inset: 0px 0px auto auto; margin: 0px; transform: translate3d(0.5px, 34px, 0px);" data-popper-placement="bottom-end">
            <li><a class="dropdown-item disabled" href="#">
                <i class="bi bi-person spo"></i>
                <?= F_userinfo_displayname() ?>
            </a></li>
            <li><a class="dropdown-item disabled" href="#">
                <i class="bi bi-envelope-at spo"></i>
                <?= F_userinfo_mail() ?>
            </a></li>
            <li><hr class="dropdown-divider"></li>
            <li><a class="dropdown-item" href="mod_profilo.php">
                <i class="bi bi-person-fill-gear spo"></i>
                Modifica Profilo
            </a></li>
            <li><a class="dropdown-item" href="passwd.php">
                <i class="bi bi-key spo"></i>
                Cambio Password
            </a></li>
            <li><a class="dropdown-item" href="/logout.php">
                <i class="bi bi-box-arrow-right spo"></i>
                Esci
            </a></li>
          </ul>
        </div>
    </nav>
    <nav aria-label="breadcrumb" class="gray2 ddcc">
        <ol class="breadcrumb">
            <li class="breadcrumb-item">
                <i class="bi bi-house-door spo"></i>
                <a href="/" class="alert-link">
                    Home
                </a>
            </li>
            <?php
            if($breadcrumb != null && is_array($breadcrumb)){
                foreach($breadcrumb as $item){ ?>
                    <li class="breadcrumb-item <?= $item["active"] ? "active" : "" ?>">
                        <i class="bi bi-<?= $item["icon"] ?> spo"></i>
                        <?php if($item["link"] != ""){ ?>
                            <a href="<?= $item["link"] ?>" class="alert-link">
                                <?= $item["text"] ?>
                            </a>
                        <?php } else { ?>
                            <?= $item["text"] ?>
                        <?php } ?>
                    </li>
                <?php } 
            } else if ($breadcrumb != "hp") {
                ?>
                <li class="breadcrumb-item active" aria-current="page">
                    ...
                </li>
                <?php
            }
            ?>
        </ol>
    </nav>
    <?php
}