#ifndef SPI_CONFIG_LOADER_H_
#define SPI_CONFIG_LOADER_H_

#include <cstdint>
#include "rayraw_const.hh"
#include "SPI_struct.hh"

namespace spi_cfg = yaenami_v3_spi::cfg;

class SPIConfigLoader
{
public :
  SPIConfigLoader();

  void read_DO_TP_EN();
  void read_TP_EN();
  void read_A_MON();
  void read_VB_SIPM();
  void read_VTH_COMP();
  void read_MIN_ENB();
  void read_DO_POL();
  void read_COMP_POL();
  // void read_MIN_CAP();
  void read_MIN_DLY();
  void read_R_SHP2();
  void read_C_SHP();
  void read_R_SHP1();
  void read_C_VGA1();
  void read_C_VGA2();
  void make_RegisterValues();

  static SPIConfigLoader& get_instance();

private :
  spi_cfg::Pll_Serializer m_spi_pll_ser[NumOfYaenami]{};
  spi_cfg::Channel        m_spi_ch[NumOfYaenami][NumOfCh]{};
  spi_cfg::Adc_Vcm_Dac    m_spi_adc_vcm_dac[NumOfYaenami]{};

  uint8_t DO_TP_EN[NumOfYaenami];

  uint8_t  ADC_R[NumOfYaenami][NumOfCh];
  uint8_t  TP_EN[NumOfYaenami][NumOfCh];
  uint8_t  A_MON[NumOfYaenami][NumOfCh];
  uint16_t VB_SIPM[NumOfYaenami][NumOfCh];
  uint16_t VTH_COMP[NumOfYaenami][NumOfCh];
  uint8_t  MIN_ENB[NumOfYaenami][NumOfCh];
  uint8_t  DO_POL[NumOfYaenami][NumOfCh];
  uint8_t  COMP_POL[NumOfYaenami][NumOfCh];
  uint8_t  MIN_CAP[NumOfYaenami][NumOfCh];
  uint8_t  MIN_DLY[NumOfYaenami][NumOfCh];
  uint8_t  R_SHP2[NumOfYaenami][NumOfCh];
  uint8_t  C_SHP[NumOfYaenami][NumOfCh];
  uint8_t  R_SHP1[NumOfYaenami][NumOfCh];
  uint8_t  C_VGA1[NumOfYaenami][NumOfCh];
  uint8_t  C_VGA2[NumOfYaenami][NumOfCh];

  uint8_t  PRBS_EN[NumOfYaenami];
  uint8_t  CAL_EN[NumOfYaenami];
  uint8_t  CAL_R[NumOfYaenami];
  uint8_t  PRBS_MODE[NumOfYaenami];

  void initialize_SPI_Values();
};

// __________________________________________________________
inline SPIConfigLoader&
SPIConfigLoader::get_instance()
{
  static SPIConfigLoader inst;
  return inst;
}


#endif
