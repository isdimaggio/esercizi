document.getElementById('password').addEventListener('input', function() {
    var password = document.getElementById('password').value;
    var progress = document.getElementById('progress-bar');
    var strength = 0;
    if (password.match(/[a-z]+/)) {
        strength += 20;
    }
    if (password.match(/[A-Z]+/)) {
        strength += 20;
    }
    if (password.match(/[0-9]+/)) {
        strength += 20;
    }
    if (password.match(/[$@#&!]+/)) {
        strength += 20;
    }
    if (password.length >= 8) {
        strength += 20;
    }
    progress.style.width = strength + '%';

    if (strength === 0 || strength === 20) {
        progress.classList.add('bg-danger');
        progress.classList.remove('bg-warning', 'bg-success', 'bg-primary');
    } else if (strength === 40 || strength === 60) {
        progress.classList.add('bg-warning');
        progress.classList.remove('bg-danger', 'bg-success', 'bg-primary');
    } else if (strength === 80) {
        progress.classList.add('bg-success');
        progress.classList.remove('bg-danger', 'bg-warning', 'bg-primary');
    } else if (strength === 100) {
        progress.classList.add('bg-primary');
        progress.classList.remove('bg-danger', 'bg-warning', 'bg-success');
    }
});