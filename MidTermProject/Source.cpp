#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <windows.h>
#include <conio.h>

using namespace std;

void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

class HangHoa {
private:
    string maHang;
    string tenHang;
    string noiSanXuat;
    string mauSac;
    string ngayNhapKho;
    double gia;
    int soLuong;
public:
    HangHoa() {
        maHang = tenHang = noiSanXuat = mauSac = ngayNhapKho = "";
        gia = 0;
        soLuong = 0;
        
    }

    HangHoa(string a, string b, string c, string d, double g, int k, string f) {
        this->maHang = a;
        this->tenHang = b;
        this->noiSanXuat = c;
        this->mauSac = d;
        this->gia = g;
        this->soLuong = k;
        this->ngayNhapKho = f; // Corrected the constructor
    }

    void setMaHang(string k) { maHang = k; }
    string getMaHang() { return maHang; }

    void setTenHang(string k) { tenHang = k; }
    string getTenHang() { return tenHang; }

    void setNoiSanXuat(string k) { noiSanXuat = k; }
    string getNoiSanXuat() { return noiSanXuat; }

    void setMauSac(string k) { mauSac = k; }
    string getMauSac() { return mauSac; }

    void setNgayNhapKho(string k) { ngayNhapKho = k; }
    string getNgayNhapKho() { return ngayNhapKho; }

    void setGia(double k) { gia = k; }
    double getGia() { return gia; }

    void setSoLuong(int k) { soLuong = k; }
    int getSoLuong() { return soLuong; }

    // Hàm đọc hàng hóa từ file
    vector<HangHoa> docHangHoaTuFile() {
        vector<HangHoa> hangHoas;
        ifstream file("HangHoa.txt");
        string maHang, tenHang, noiSanXuat, mauSac, ngayNhapKho;
        double gia;
        int soLuong;

        while (file >> maHang >> tenHang >> noiSanXuat >> mauSac >> gia >> soLuong >> ngayNhapKho) {
            hangHoas.emplace_back(maHang, tenHang, noiSanXuat, mauSac, gia, soLuong, ngayNhapKho);
        }
        file.close();
        return hangHoas;
    }

    // Hàm lưu hàng hóa vào file
    void luuHangHoaVaoFile(vector<HangHoa> hangHoas) {
        ofstream file("HangHoa.txt");
        for (auto hh : hangHoas) {
            file << hh.getMaHang() << " " << hh.getTenHang() << " " << hh.getGia() << " " << hh.getSoLuong() << endl;
        }
        file.close();
    }

    

    // Hàm tìm kiếm hàng hóa
    void timKiemHangHoa(vector<HangHoa> hangHoas) {
        string tuKhoa;
        cout << "Nhap ma hang hoac ten hang de tim: ";
        cin.ignore();
        getline(cin, tuKhoa);

        bool found = false;

        // Display header outside the loop
        cout << setw(10) << left << "Ma Hang"
            << setw(20) << left << "Ten Hang"
            << setw(15) << left << "Noi San Xuat"
            << setw(10) << left << "Mau Sac"
            << setw(10) << left << "Gia"
            << setw(15) << left << "Ngay Nhap Kho"
            << setw(10) << left << "So Luong" << endl;

        for (auto hh : hangHoas) {
            if (hh.getMaHang() == tuKhoa || hh.getTenHang().find(tuKhoa) != string::npos) {
                hh.hienThi(); // Call to display the matched item
                found = true;
            }
        }

        if (!found) {
            cout << "Khong tim thay hang hoa!" << endl;
        }
    }

    // Hiển thị thông tin hàng hóa
    void hienThi() const {
        cout << setw(10) << left << maHang
            << setw(20) << left << tenHang
            << setw(15) << left << noiSanXuat
            << setw(10) << left << mauSac
            << setw(10) << left << gia
            << setw(15) << left << ngayNhapKho
            << setw(10) << left << soLuong << endl;
    }

    // Hàm hiển thị hàng hóa
    void hienThiHangHoa(const vector<HangHoa>& hangHoas) {
        cout << setw(10) << left << "Ma Hang"
            << setw(20) << left << "Ten Hang"
            << setw(15) << left << "Noi San Xuat"
            << setw(10) << left << "Mau Sac"
            << setw(10) << left << "Gia"
            << setw(15) << left << "Ngay Nhap Kho"
            << setw(10) << left << "So Luong" << endl;

        for (auto hh : hangHoas) {
            hh.hienThi(); // Gọi hàm hiển thị
        }
    }

    // Hàm thêm hàng hóa
    void themHangHoa(vector<HangHoa>& hangHoas) {
        string maHang, tenHang, noiSanXuat, mauSac, ngayNhapKho;
        double gia;
        int soLuong;

        cout << "Nhap ma hang (4 ki tu): ";
        cin >> maHang;
        if (maHang.length() != 4) {
            cout << "Ma hang phai co 4 ki tu!" << endl;
            return;
        }

        // Input validation for other fields can be added similarly
        cout << "Nhap ten hang: ";
        cin.ignore(); // Clear input buffer
        getline(cin, tenHang);

        cout << "Nhap noi san xuat: ";
        getline(cin, noiSanXuat);

        cout << "Nhap mau sac: ";
        getline(cin, mauSac);

        cout << "Nhap gia: ";
        cin >> gia;

        cout << "Nhap so luong: ";
        cin >> soLuong;

        cout << "Nhap ngay nhap kho: ";
        cin.ignore(); // Clear input buffer
        getline(cin, ngayNhapKho);

        hangHoas.emplace_back(maHang, tenHang, noiSanXuat, mauSac, gia, soLuong, ngayNhapKho);
        luuHangHoaVaoFile(hangHoas);
        cout << "Them hang hoa thanh cong!" << endl;
    }

    // Hàm xóa hàng hóa
    void xoaHangHoa(vector<HangHoa>& hangHoas) {
        string maHang;
        cout << "Nhap ma hang can xoa: ";
        cin >> maHang;
        auto it = remove_if(hangHoas.begin(), hangHoas.end(), [&](HangHoa hh) { return hh.getMaHang() == maHang; });
        if (it != hangHoas.end()) {
            hangHoas.erase(it, hangHoas.end());
            luuHangHoaVaoFile(hangHoas);
            cout << "Xoa hang hoa thanh cong!" << endl;
        }
        else {
            cout << "Ma hang khong ton tai!" << endl;
        }
    }

    // Hàm sửa hàng hóa
    void suaHangHoa(vector<HangHoa>& hangHoas) {
        string maHang;
        cout << "Nhap ma hang can sua: ";
        cin >> maHang;

        for (auto& hh : hangHoas) {
            if (hh.getMaHang() == maHang) {
                cout << "Nhap ten hang moi: ";
                string tenHangMoi; cin >> tenHangMoi;
                setTenHang(tenHangMoi);

                cout << "Nhap gia moi: ";
                double giaMoi; cin >> giaMoi;
                setGia(giaMoi);

                cout << "Nhap so luong moi: ";
                int soLuongMoi; cin >> soLuongMoi;
                setSoLuong(soLuongMoi);

                luuHangHoaVaoFile(hangHoas);
                cout << "Sua hang hoa thanh cong!" << endl;
                return;
            }
        }
        cout << "Ma hang khong ton tai!" << endl;
    }
};


// Định nghĩa lớp DonHang
class DonHang {
private:
    int soThuTu;
    string tenKhachHang;
    string diaChi;
    string soDienThoai;
    string ngayDatHang;
    double tongTien;
public:
    DonHang() { 
        soThuTu = 0;
        tenKhachHang = diaChi = soDienThoai = ngayDatHang = "";
        tongTien = 0;
    }

    DonHang(int soThuTu, string tenKhachHang, string diaChi, string soDienThoai, string ngayDatHang, double tongTien, vector<pair<string, int>> hangDat)
        : soThuTu(soThuTu), tenKhachHang(tenKhachHang), diaChi(diaChi), soDienThoai(soDienThoai), ngayDatHang(ngayDatHang), tongTien(tongTien), hangDat(hangDat) {}

    void setSoThuTu(int k) { soThuTu = k; }
    int getSoThuTu() { return soThuTu; }

    void setTenKhachHang(string k) { tenKhachHang = k; }
    string getTenKhachHang() { return tenKhachHang; }

    void setDiaChi(string k) { diaChi = k; }
    string getDiaChi() { return diaChi; }

    void setSoDienThoai(string k) { soDienThoai = k; }
    string getSoDienThoai() { return soDienThoai; }

    void setNgayDatHang(string k) { ngayDatHang = k; }
    string getNgayDatHang() { return ngayDatHang; }

    void setTongTien(double k) { tongTien = k; }
    double getTongTien() { return tongTien; }


    vector<pair<string, int>> hangDat; 
    // Hàm lưu đơn hàng vào file
    void luuDonHangVaoFile(const vector<DonHang>& donHangs) {
        ofstream file("DonHang.txt", ios::app);
        for (auto dh : donHangs) {
            file << dh.getTenKhachHang() << endl;
            file << dh.getDiaChi() << endl;
            file << dh.getSoDienThoai() << endl;
            file << dh.getNgayDatHang() << endl;
            file << dh.getTongTien() << endl;
            for (const auto& item : dh.hangDat) {
                file << item.first << " " << item.second << endl;
            }
            file << endl; // Đảm bảo có dòng trống để tách biệt các đơn hàng
        }
        file.close();
    }

    // Hàm hiển thị danh sách đơn hàng
    void hienThiDonHang(const vector<DonHang>& donHangs) {
        cout << setw(10) << left << "STT"
            << setw(20) << left << "Ten Khach"
            << setw(20) << left << "Dia Chi"
            << setw(15) << left << "SDT"
            << setw(15) << left << "Ngay Dat"
            << setw(10) << left << "Tong Tien" << endl;

        for (auto dh : donHangs) {
            cout << setw(10) << left << dh.getSoThuTu()
                << setw(20) << left << dh.getTenKhachHang()
                << setw(20) << left << dh.getDiaChi()
                << setw(15) << left << dh.getSoDienThoai()
                << setw(15) << left << dh.getNgayDatHang()
                << setw(10) << left << dh.getTongTien() << endl;
        }
    }

    // Hàm xóa đơn hàng
    void xoaDonHang(vector<DonHang>& donHangs) {
        int stt;
        cout << "Nhap STT don hang can xoa: ";
        cin >> stt;

        auto it = remove_if(donHangs.begin(), donHangs.end(), [stt](DonHang dh) { return dh.getSoThuTu() == stt; });
        if (it != donHangs.end()) {
            donHangs.erase(it, donHangs.end());
            luuDonHangVaoFile(donHangs);
            cout << "Xoa don hang thanh cong!" << endl;
        }
        else {
            cout << "STT don hang khong ton tai!" << endl;
        }
    }

    // Hàm cập nhật đơn hàng
    void capNhatDonHang(vector<DonHang>& donHangs) {
        int stt;
        cout << "Nhap STT don hang can cap nhat: ";
        cin >> stt;

        auto it = find_if(donHangs.begin(), donHangs.end(), [stt](DonHang dh) { return dh.getSoThuTu() == stt; });
        if (it != donHangs.end()) {
            cout << "Nhap ten khach hang moi: ";
            cin.ignore();
            string tenKHMoi; getline(cin, tenKHMoi);
            it->setTenKhachHang(tenKHMoi);

            cout << "Nhap dia chi moi: ";
            string diaChiMoi; getline(cin, diaChiMoi);
            it->setDiaChi(diaChiMoi);

            cout << "Nhap so dien thoai moi: ";
            string soDienThoaiMoi; getline(cin, soDienThoaiMoi);
            it->setSoDienThoai(soDienThoaiMoi);

            cout << "Nhap ngay dat hang moi: ";
            string ngayDatHangMoi; getline(cin, ngayDatHangMoi);
            it->setNgayDatHang(ngayDatHangMoi);
            luuDonHangVaoFile(donHangs);
            cout << "Cap nhat don hang thanh cong!" << endl;
        }
        else {
            cout << "STT don hang khong ton tai!" << endl;
        }
    }

    // Hàm xử lý đơn hàng
    void xuLyDonHang(vector<HangHoa>& hangHoas, vector<DonHang>& donHangs) {
        int luaChon;
        do {
            cout << "1. Hien thi danh sach don hang" << endl;
            cout << "2. Xoa don hang" << endl;
            cout << "3. Cap nhat don hang" << endl;
            cout << "4. Thoat" << endl;
            cout << "Chon chuc nang: ";
            cin >> luaChon;

            switch (luaChon) {
            case 1:
                hienThiDonHang(donHangs);
                break;
            case 2:
                xoaDonHang(donHangs);
                break;
            case 3:
                capNhatDonHang(donHangs);
                break;
            case 4:
                cout << "Thoat ra menu chinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
        } while (luaChon != 4);
    }

    // Hàm xử lý đặt hàng
    void datHang(vector<HangHoa>& hangHoas, vector<DonHang>& donHangs) {
        string tenKhachHang, diaChi, soDienThoai, ngayDatHang;
        double tongTien = 0.0;
        vector<pair<string, int>> hangDat;

        cout << "Nhap ten khach hang: ";
        cin.ignore();
        getline(cin, tenKhachHang);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
        cout << "Nhap so dien thoai: ";
        getline(cin, soDienThoai);
        cout << "Nhap ngay dat hang: ";
        getline(cin, ngayDatHang);

        while (true) {
            string maHang;
            int soLuong;

            cout << "Nhap ma hang (hoac 'exit' de thoat): ";
            cin >> maHang;
            if (maHang == "exit") break;

            cout << "Nhap so luong: ";
            cin >> soLuong;

            auto it = find_if(hangHoas.begin(), hangHoas.end(), [&](HangHoa hh) { return hh.getMaHang() == maHang; });
            if (it != hangHoas.end() && it->getSoLuong() >= soLuong) {
                // Cập nhật số lượng trong hàng hóa
                it->setSoLuong(it->getSoLuong() - soLuong);
                tongTien += it->getGia() * soLuong;
                hangDat.emplace_back(maHang, soLuong);
                cout << "Da them " << soLuong << " " << it->getTenHang() << " vao don hang." << endl;
            }
            else {
                cout << "Khong co hang hoa hoac so luong khong du!" << endl;
            }
        }

        if (!hangDat.empty()) {
            int soThuTu = donHangs.size() + 1;
            DonHang donHang(soThuTu, tenKhachHang, diaChi, soDienThoai, ngayDatHang, tongTien, hangDat);
            donHangs.push_back(donHang);
            luuDonHangVaoFile(donHangs); // Lưu đơn hàng sau khi tạo
            cout << "Don hang dang cho xu ly!" << endl;
        }
        else {
            cout << "Khong co san pham nao duoc dat!" << endl;
        }
    }

    // Hàm đọc đơn hàng từ file
    vector<DonHang> docDonHangTuFile() {
        vector<DonHang> donHangs;
        ifstream file("DonHang.txt");
        string tenKhachHang, diaChi, soDienThoai, ngayDatHang;
        double tongTien;

        while (getline(file, tenKhachHang) && !tenKhachHang.empty()) {
            getline(file, diaChi);
            getline(file, soDienThoai);
            getline(file, ngayDatHang);
            file >> tongTien;
            file.ignore(); // Dùng để bỏ qua ký tự newline

            vector<pair<string, int>> hangDat;
            string maHang;
            while (file >> maHang) {
                int soLuong;
                file >> soLuong;
                hangDat.emplace_back(maHang, soLuong);
            }
            file.ignore(); // Dùng để bỏ qua ký tự newline

            // Tạo đơn hàng
            int soThuTu = donHangs.size() + 1;
            DonHang donHang(soThuTu, tenKhachHang, diaChi, soDienThoai, ngayDatHang, tongTien, hangDat);
            donHangs.push_back(donHang);
        }

        file.close();
        return donHangs;
    }
};

class QuanLy {
private:
    string user, password;
public:
    QuanLy() { user = password = ""; }
    QuanLy(string a, string b) { user = a; password = b; }

    // Hàm xử lý đăng nhập
    bool check(string userInput, string passInput) {
        ifstream file("Admin.txt");
        string user, password;

        // Kiểm tra nếu file mở thành công
        if (!file.is_open()) {
            cout << "Khong the mo file.\n";
            return false;
        }

        while (file >> user >> password) {
            if (user == userInput && password == passInput) {
                return true; // Đăng nhập thành công
            }
        }
        file.close(); // Đóng tệp 
        return false; // Đăng nhập không thành công
    }

    bool dangNhap() {
        // Thêm menu đăng nhập
        const string title = "DANG NHAP HE THONG";
        int totalLength = title.length() + 4;
        string border(totalLength, '*');

        setColor(14, 0); // Màu vàng cho dấu *
        cout << border << endl;
        setColor(10, 0); // Màu xanh lá cây cho chữ
        cout << "* " << title << " *" << endl;
        setColor(14, 0); // Quay lại màu vàng cho dấu *
        cout << border << endl;

        // Lưu màu mặc định
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        int defaultTextColor = csbi.wAttributes & 0x0F;
        string userInput, passInput;
        int attempts = 0;

        while (attempts < 3) {
            setColor(10, 0); // Màu xanh lá cây cho chữ "User:" và "Password:"
            cout << "User: ";
            getline(cin, userInput);

            cout << "Password: ";
            passInput.clear();

            char ch;
            while ((ch = _getch()) != '\r') { // Đọc từng ký tự cho đến khi nhấn Enter
                if (ch == '\b') { // Nếu nhấn Backspace
                    if (!passInput.empty()) {
                        cout << "\b \b"; // Xóa ký tự trước đó trên màn hình
                        passInput.pop_back(); // Xóa ký tự trong chuỗi mật khẩu
                    }
                }
                else {
                    passInput += ch; // Thêm ký tự vào mật khẩu
                    cout << '*'; // Hiển thị dấu *
                }
            }
            cout << endl; // Xuống dòng sau khi nhập mật khẩu

            if (check(userInput, passInput)) {
                cout << "Dang nhap thanh cong!\n";
                return true;
            }
            else {
                cout << "Sai user hoac password. Vui long nhap lai.\n";
                attempts++;
            }

            if (attempts == 3) {
                cout << "Ban da nhap sai 3 lan. Thoat khoi he thong.\n";
                exit(0); // Hoặc bạn có thể sử dụng return để quay lại menu chính
            }
        }
    }

    // Hàm hiển thị menu chính
    void hienThiMenu(vector<HangHoa>& hangHoas, vector<DonHang>& donHangs, HangHoa&hh,DonHang& dh) {
        int luaChon;
        do {
            cout << "Menu chinh:" << endl;
            cout << "1. Hien thi thong tin hang hoa" << endl;
            cout << "2. Tim kiem hang hoa" << endl;
            cout << "3. Dat hang" << endl;
            cout << "4. Quan ly don hang" << endl;
            cout << "5. Quan ly hang hoa" << endl;
            cout << "6. Thoat" << endl;
            cout << "Chon chuc nang: ";
            cin >> luaChon;

            switch (luaChon) {
            case 1:
                hh.hienThiHangHoa(hangHoas);
                break;
            case 2:
                hh.timKiemHangHoa(hangHoas);
                break;
            case 3:
                dh.datHang(hangHoas, donHangs);
                break;
            case 4:
                dh.xuLyDonHang(hangHoas, donHangs);
                break;
            case 5: {
                int luaChonQL;
                do {
                    cout << "1. Them hang hoa" << endl;
                    cout << "2. Xoa hang hoa" << endl;
                    cout << "3. Sua hang hoa" << endl;
                    cout << "4. Thoat" << endl;
                    cout << "Chon chuc nang: ";
                    cin >> luaChonQL;

                    switch (luaChonQL) {
                    case 1:
                        hh.themHangHoa(hangHoas);
                        break;
                    case 2:
                        hh.xoaHangHoa(hangHoas);
                        break;
                    case 3:
                        hh.suaHangHoa(hangHoas);
                        break;
                    case 4:
                        cout << "Thoat ra menu chinh." << endl;
                        break;
                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                    }
                } while (luaChonQL != 4);
                break;
            }
            case 6:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
        } while (luaChon != 6);
    }
};


// Hàm chính
int main() {
    HangHoa hh;
    DonHang dh;
    vector <HangHoa> hangHoas = hh.docHangHoaTuFile();
    vector <DonHang> donHangs = dh.docDonHangTuFile();
    QuanLy ql;
    if (ql.dangNhap()) {
        ql.hienThiMenu(hangHoas,donHangs,hh,dh);
    }
    return 0;
}