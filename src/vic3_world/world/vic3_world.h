#ifndef SRC_VIC3WORLD_WORLD_VIC3WORLD_H
#define SRC_VIC3WORLD_WORLD_VIC3WORLD_H



#include <map>
#include <set>

#include "external/commonItems/Localization/LocalizationDatabase.h"
#include "src/vic3_world/countries/vic3_country.h"
#include "src/vic3_world/provinces/vic3_province_definitions.h"
#include "src/vic3_world/states/state_region.h"
#include "src/vic3_world/states/vic3_state.h"



namespace vic3
{

struct WorldOptions
{
   std::map<int, Country> countries;
   std::map<int, State> states;
   std::map<std::string, vic3::StateRegion> state_regions;
   ProvinceDefinitions province_definitions;
   std::map<int, std::set<std::string>> acquired_technologies;
   commonItems::LocalizationDatabase localizations = commonItems::LocalizationDatabase("english", {});
};


class World
{
  public:
   explicit World(WorldOptions world_options):
       countries_(std::move(world_options.countries)),
       states_(std::move(world_options.states)),
       state_regions_(std::move(world_options.state_regions)),
       province_definitions_(world_options.province_definitions),
       acquired_technologies_(std::move(world_options.acquired_technologies)),
       localizations_(std::move(world_options.localizations))
   {
   }

   [[nodiscard]] const std::map<int, Country>& GetCountries() const { return countries_; }
   [[nodiscard]] const std::map<int, State>& GetStates() const { return states_; }
   [[nodiscard]] const std::map<std::string, vic3::StateRegion>& GetStateRegions() const { return state_regions_; }
   [[nodiscard]] const ProvinceDefinitions& GetProvinceDefinitions() const { return province_definitions_; }
   [[nodiscard]] const std::map<int, std::set<std::string>>& GetAcquiredTechnologies() const
   {
      return acquired_technologies_;
   }
   [[nodiscard]] const commonItems::LocalizationDatabase& GetLocalizations() const { return localizations_; }

  private:
   std::map<int, Country> countries_;
   std::map<int, State> states_;
   std::map<std::string, vic3::StateRegion> state_regions_;
   ProvinceDefinitions province_definitions_;
   std::map<int, std::set<std::string>> acquired_technologies_;
   commonItems::LocalizationDatabase localizations_;
};

}  // namespace vic3



#endif  // SRC_VIC3WORLD_WORLD_VIC3WORLD_H