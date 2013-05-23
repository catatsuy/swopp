void Exec() {
#pragma omp parallel num_threads(8)
  {
#pragma omp for
    for (uint i = 0; i < modules_.size(); i++) {
      modules_[i]->Always();
    }
#pragma omp for
    for (uint i = 0; i < registers_.size(); i++) {
      registers_[i]->Update();
    }
  }
}
