FTP_SRCS := \
	$(NXDK_DIR)/lib/ftp/ftpConnection.cpp \
        $(NXDK_DIR)/lib/ftp/ftpServer.cpp

FTP_OBJS = $(addsuffix .obj, $(basename $(FTP_SRCS)))

$(NXDK_DIR)/lib/libftp.lib: $(FTP_OBJS)

main.exe: $(NXDK_DIR)/lib/libftp.lib

CLEANRULES += clean-ftp

.PHONY: clean-ftp
clean-ftp:
	$(VE)rm -f $(FTP_OBJS) $(NXDK_DIR)/lib/libftp.lib
