///
/// \file   MonitorObject.h
/// \author Barthelemy von Haller
///

#ifndef QUALITYCONTROL_LIBS_CORE_MONITOROBJECT_H_
#define QUALITYCONTROL_LIBS_CORE_MONITOROBJECT_H_

#include "Quality.h"
#include <map>
#include <TObject.h>

namespace AliceO2 {
namespace QualityControl {
namespace Core {

/// \brief  This class keeps the metadata about one published object.
///
/// \author Barthelemy von Haller
class MonitorObject
{
  public:
    /// Default constructor
    MonitorObject();
    MonitorObject(const std::string &name, TObject *object);

    /// Destructor
    virtual ~MonitorObject();

    const std::string &getName() const
    {
      return mName;
    }

    void setName(const std::string &name)
    {
      mName = name;
    }

    const Quality &getQuality() const
    {
      return mQuality;
    }

    void setQuality(const Quality &quality)
    {
      mQuality = quality;
    }

    TObject *getObject() const
    {
      return mObject;
    }

    void setObject(TObject *object)
    {
      mObject = object;
    }

    const std::map<std::string, std::string> &getCheckers() const
    {
      return mCheckers;
    }

    /// \brief Add a checker to be executed on this object when computing the quality.
    /// If a checker with the same name already exists it will be replaced by this check class name.
    /// Several checkers can be added for the same checker class name, but with different names (and
    /// they will get different configuration).
    /// \author Barthelemy von Haller
    /// \param name Arbitrary name to identify this checker.
    /// \param checkClassName The name of the class of the checker.
    void addCheck(const std::string name, const std::string &checkClassName)
    {
      mCheckers[name] = checkClassName;
    }

  private:
    std::string mName;
    Quality mQuality;
    TObject *mObject;
    std::map<std::string /* name */, std::string /* checker class name */> mCheckers;
};

} // namespace Core
} // namespace QualityControl
} // namespace AliceO2

#endif // QUALITYCONTROL_LIBS_CORE_MONITOROBJECT_H_
