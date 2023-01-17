
%extend AutoDocDescription{
	std::string __repr__() {
			return $self->str();
		}
}
%extend AutoDocReturn{
		std::string __repr__() {
			return $self->description().str();
		}
}
%extend AutoDocParameter{
		std::string __repr__() {
			return $self->description().str();
		}
}
