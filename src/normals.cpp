#include <nori/integrator.h>

NORI_NAMESPACE_BEGIN

class NormalIntegrator : public Integrator {
public:
  NormalIntegrator(const PropertyList &props) {
    m_myProperty = props.getString("myProperty");
    std::cout << "Parameter value was: " << m_myProperty << '\n';
  }

  // Compute the radiance val for a ray. (Just green now)
  Color3f Li (const Scene *scene, Sampler *sampler, const Ray3f &ray) const {
    return Color3f(0,1,0);
  }

  std::string toString() const {
    return tfm::format(
      "NormalIntegrator[\n]"
      "  myProperty = \"%s\"\n"
      "]",
      m_myProperty
    );
  }
protected:
  std::string m_myProperty;
};

NORI_REGISTER_CLASS(NormalIntegrator, "normals");
NORI_NAMESPACE_END
